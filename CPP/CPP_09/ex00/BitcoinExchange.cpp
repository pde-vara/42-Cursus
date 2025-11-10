/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <pde-vara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 15:24:47 by lde-merc          #+#    #+#             */
/*   Updated: 2025/09/24 16:16:07 by pde-vara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}


BitcoinExchange::BitcoinExchange(const std::string& fileName) {
	std::ifstream file(fileName.c_str());
	if (!file)
		throw std::runtime_error("Couldn't load data");
	
	std::string line;
	while (std::getline(file, line))
	{
		std::stringstream sts(line);
		std::string date, valueStr;
		if (!std::getline(sts, date, ',') || !std::getline(sts, valueStr))
			continue;
		_rates[date] = std::atof(valueStr.c_str());
	}
}



float BitcoinExchange::getRate(const std::string& date) const 
{
	std::map<std::string, float>::const_iterator it;
	it = _rates.lower_bound(date);
	
	if (it->first == date && it != _rates.end()) {
		return (it->second);
	}
	if (it == _rates.begin())
		throw std::runtime_error("No rate available before this date: " + date);
	
	--it;
	return it->second;
}


BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)  : _rates(other._rates) {}




BitcoinExchange::~BitcoinExchange() {}



BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
	if (this != &other)
		_rates = other._rates;
	return *this;
}

