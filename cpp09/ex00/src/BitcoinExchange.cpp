/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 20:07:53 by imurugar          #+#    #+#             */
/*   Updated: 2024/01/23 13:45:36 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

#include <fstream>
#include <iostream>
#include <ctime>
#include <cstring>
#include <sstream>

BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	*this = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &src)
{
	if (this != &src)
		this->_map = src._map;
	return *this;
}

double BitcoinExchange::stringToFloat(const std::string &str)
{
	char *endPtr;
	float result = std::strtof(str.c_str(), &endPtr);
	
	if (*endPtr) throw std::runtime_error("invalid value => " + str);
	if (result < 0) throw std::runtime_error("not a positive number");
	return result;
}

bool isLeapYear(int year) {
	//Leap year is divisible by 4 but not by 100 but if its divisible by 400 then is it
	//ex: 1900 => 1900/4 = 475; but 1900/100 = 19; 1900/400 = 4.75 (non divisible by 400)
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool isValidDate(int year, int month, int day) {
    if (month < 1 || month > 12) {
        return false;
    }

    int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // Adjust February days for leap years
    if (month == 2 && isLeapYear(year)) {
        daysInMonth[2] = 29;
    }
	
    return day >= 1 && day <= daysInMonth[month];
}

bool isDateInCorrectFormat(const std::string& date) {
    int year, month, day;
    char format;

    std::istringstream ss(date);
    ss >> year >> format >> month >> format >> day;
	
    if (ss.fail() || ss.peek() != EOF || format != '-' || !isValidDate(year, month, day)) {
        return false;
    }

    return true;
}

bool BitcoinExchange::validateDate(const std::string &date) {
	const char *format = "%Y-%m-%d";
	struct tm tp;
	
	if (strptime(date.c_str(), format, &tp) == NULL) return false;
	if (!std::isdigit(date[date.size() - 1])) return false;
	
	return isDateInCorrectFormat(date);
}

void BitcoinExchange::trimSpaces(std::string &s)
{
	s.erase(s.find_last_not_of(' ') + 1);
	s.erase(0, s.find_first_not_of(' '));
}

void BitcoinExchange::fillMap(std::string line)
{
	size_t findPos = line.find(',');
  	if (findPos == std::string::npos)
    	throw std::runtime_error("fatal: cannot find delimiter");
	
	trimSpaces(line);
	
	std::string key = line.substr(0, findPos);
	std::string value = line.substr(findPos + 1);

	this->_map[key] = stringToFloat(value);
}

void BitcoinExchange::loadDB()
{
	std::ifstream db("./data.csv");
	if (!db.is_open())
		throw std::runtime_error("could not open file.");

	std::string line;
	std::getline(db, line); // skip first line in db file
	while (std::getline(db, line))
	{
		// for each line, store value into {map <key, value>}
		fillMap(line);
	}
}

void BitcoinExchange::parseInput(const std::string &file)
{
	std::ifstream input(file.c_str());
	if (!input.is_open())
		throw std::runtime_error("could not open: " + file);
	
	std::string line;
	std::getline(input, line);
	while (std::getline(input, line))
	{
		//check date
		size_t delimiter = line.find('|');
		if (delimiter == std::string::npos)
		{
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}
		std::string dat = line.substr(0, delimiter);
		trimSpaces(dat);
		if (!validateDate(dat)) {
        	std::cout << "Error: bad input => " << dat << std::endl;
			continue;
      	}
		//check value
		try
		{
			std::string tmp = line.substr(delimiter + 1);
			float nbr = stringToFloat(tmp);
			if (nbr > 1000) throw std::runtime_error("too large a number.");
			
			std::cout << dat << " => ";
			
			std::map<std::string, float>::iterator it = (this->_map.lower_bound(dat));
			if (it == _map.end())
				--it;
			
			std::cout << nbr << " = " << nbr * it->second << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << "Error: " << e.what() << std::endl;
		}
	}
	
}

void BitcoinExchange::process(std::string file)
{
	(void)file;
	try {
		loadDB();
	}
	catch (const std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return;
	}

	try {
		this->parseInput(file);
	}
	catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
}
