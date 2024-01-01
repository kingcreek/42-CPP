/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 20:07:53 by imurugar          #+#    #+#             */
/*   Updated: 2023/12/31 21:06:21 by imurugar         ###   ########.fr       */
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
	
	if (*endPtr) throw std::runtime_error("invalid value");
	if (result < 0) throw std::runtime_error("not a positive number");
	return result;
}

bool BitcoinExchange::isValidDate(const std::tm &timeStruct)
{
	return timeStruct.tm_year >= 0 && timeStruct.tm_mon >= 0 && timeStruct.tm_mday > 0;
}

bool BitcoinExchange::validateDate(const std::string &s)
{
	bool ret = true;
	const char *format = "%Y-%m-%d";
	struct tm tp;

	if (strptime(s.c_str(), format, &tp) == NULL)
		ret = false;
	if (!std::isdigit(s[s.size() - 1]))
		ret = false;
	for(size_t i = 0; i < s.length(); i++)
		if(!std::isdigit(s[i]) && s[i] != '-')
			ret = false;

	return ret;
}

std::time_t BitcoinExchange::getTimestamp(const std::string &dateString)
{
	std::tm timeStruct = {};

	std::istringstream dateStream(dateString.c_str());
	dateStream >> std::get_time(&timeStruct, "%Y-%m-%d");

	// Check if parsing was successful
	if (dateStream.fail() || !isValidDate(timeStruct) || !validateDate(dateString))
	{
		throw std::runtime_error("Error: Invalid date format");
	}

	timeStruct.tm_hour = 12;
	timeStruct.tm_min = 0;
	timeStruct.tm_sec = 0;

	std::time_t timestamp = std::mktime(&timeStruct);
	if (timestamp == -1)
	{
		throw std::runtime_error("Error: Could not convert date to timestamp");
	}

	return timestamp;
}

void BitcoinExchange::fillMap(const std::string line)
{
	size_t findPos = line.find(',');
  	if (findPos == std::string::npos)
    	throw std::runtime_error("fatal: cannot find delimiter");
	
	std::string key = line.substr(0, findPos);
	std::string value = line.substr(findPos + 1);
	this->_map[getTimestamp(key)] = stringToFloat(value);
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

void BitcoinExchange::parseInput(std::string &file)
{
	std::ifstream input(file);
	if (!input.is_open())
		throw std::runtime_error("Error: could not open: " + file);
	
	std::string line;
	std::getline(input, line);
	while (std::getline(input, line))
	{
		//check date
		std::string dat = line.substr(0, line.find('|') - 1);
		if (!validateDate(dat)) {
        	std::cout << "Error: bad input => " << dat << std::endl;
			continue;
      	}
		//check value
		try
		{
			//check contains '|'
			size_t findPos = line.find('|');
			if (findPos == std::string::npos)
				throw std::runtime_error("fatal: cannot find delimiter");
				
			std::string tmp = line.substr(findPos + 2);
			float nbr = stringToFloat(tmp);
			if (nbr > 1000) throw std::runtime_error("number too large");
			
			std::cout << dat << " => ";
			
			std::map<std::time_t, float>::iterator it = (this->_map.lower_bound(getTimestamp(dat)));
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
		std::cerr << e.what() << std::endl;
	}
}
