/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 20:07:24 by imurugar          #+#    #+#             */
/*   Updated: 2023/12/31 21:04:02 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <iostream>
#include <map>
#include <string>

class BitcoinExchange
{

private:
	std::map<std::time_t, float> _map;

	double stringToFloat(const std::string &str);
	bool isValidDate(const std::tm &timeStruct);
	bool validateDate(const std::string &s);
	std::time_t getTimestamp(const std::string &dateString);
	void loadDB();
	void parseInput(std::string &file);
	void fillMap(const std::string line);

public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &);
	BitcoinExchange &operator=(const BitcoinExchange &);
	~BitcoinExchange();

	void process(std::string file);

};

#endif
