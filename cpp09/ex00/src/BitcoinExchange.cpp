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
#include <iomanip>

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
	double result = std::strtod(str.c_str(), &endPtr);
	
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
    ss >> year >> format;

    std::string dateString;
    ss >> dateString;

    size_t dashPos = dateString.find('-');
    if (dashPos == std::string::npos || dashPos + 1 >= dateString.length()) {
        std::cout << "Error: Invalid format => " << date << std::endl;
        return false;
    }

    std::string monthStr = dateString.substr(0, dashPos);
    std::string dayStr = dateString.substr(dashPos + 1);

    if (monthStr.length() != 2 || dayStr.length() != 2) {
        std::cout << "Error: Invalid month or day format => " << date << std::endl;
        return false;
    }

    month = atoi(monthStr.c_str());
    day = atoi(dayStr.c_str());

    if (ss.fail() || ss.peek() != EOF || format != '-' || !isValidDate(year, month, day)) {
        std::cout << "Error: Invalid date => " << date << std::endl;
        return false;
    }
	
	if (!isValidDate(year, month, day))
    {
        std::cout << "Error: Invalid month or day => " << date << std::endl;
        return false;
    }
	
    return true;
}

bool BitcoinExchange::validateDate(const std::string &date) {
	const char *format = "%Y-%m-%d";
	struct tm tp;
	
	if (strptime(date.c_str(), format, &tp) == NULL) {
		std::cout << "Error: bad input => " << date << std::endl;
		return false;
	}
	if (!std::isdigit(date[date.size() - 1])){
		std::cout << "Error: bad input => " << date << std::endl;
		return false;
	}
	
	if (tp.tm_year < 108 || (tp.tm_year == 108 && (tp.tm_mon < 9 || (tp.tm_mon == 9 && tp.tm_mday < 31)))) {
		std::cout << "Error: Bitcoint did not exist in => " << date << std::endl;
        return false;
    }
	
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

const std::string BitcoinExchange::formatFloat(double num) {
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(2) << num;
    std::string result = oss.str();
    size_t dotPosition = result.find('.');

    if (dotPosition != std::string::npos) {
        size_t lastNonZero = result.find_last_not_of('0');

        if (lastNonZero != std::string::npos && result[lastNonZero] == '.') {
            result.erase(lastNonZero);
        } else {
            result.erase(result.find_last_not_of('0') + 1);
        }
    }
    return result;
}

int BitcoinExchange::dateDifference(const std::string& date1, const std::string& date2) {
    int day1 = std::atoi(date1.substr(8, 2).c_str());
    int day2 = std::atoi(date2.substr(8, 2).c_str());
    return std::abs(day2 - day1);
}

std::map<std::string, double>::iterator BitcoinExchange::findNearestDate(const std::string& targetDate) {
    std::map<std::string, double>::iterator it = _map.lower_bound(targetDate);
    if (it == _map.begin())
        return it;

    std::map<std::string, double>::iterator prev = it;
	prev--;
	if (it == _map.end())
		return prev;
    int diffPrev = dateDifference(targetDate, prev->first);
    int diffNext = dateDifference(targetDate, it->first);

    return (diffPrev < diffNext) ? prev : it;
}

void BitcoinExchange::parseInput(const std::string &file)
{
	std::ifstream input(file.c_str());
	if (!input.is_open())
		throw std::runtime_error("could not open: " + file);
	
	std::string line;
	std::getline(input, line);
	if (line != "date | value")
	{
		std::cout << "Error: Invalid input file, missing or incorrect header \"date | value\"" << std::endl;
		return;
	}
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
        	//std::cout << "Error: bad input => " << dat << std::endl;
			continue;
      	}
		//check value
		try
		{
			std::string tmp = line.substr(delimiter + 1);
			trimSpaces(tmp);
			if (tmp == ""){
				std::cout << "Error: bad input => " << tmp << std::endl;
				continue;
			}
			double nbr = stringToFloat(tmp);
			if ((float)nbr > 1000) throw std::runtime_error("too large a number");
			
			std::cout << dat << " => ";

            std::map<std::string, double>::iterator it = findNearestDate(dat);
            if (it == _map.end())
                --it;

            double result = nbr * it->second;

            // Utilizar la función auxiliar para formatear el número
            std::cout  << nbr << " = " << formatFloat(result) << std::endl;
			
		}
		catch(const std::exception& e)
		{
			std::cout << "Error: " << e.what() << std::endl;
		}
	}
	
}

void BitcoinExchange::process(std::string file)
{
	try {
		loadDB();
		parseInput(file);
	}
	catch (std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
		return;
	}
}
