
#pragma once
#include <string>
#include <map>
#include <fstream>
#include <sstream>
#include <iostream>
#include <cstdlib>

class BitcoinExchange {
	private:
		std::map<std::string, float> _rates;

	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange(const std::string& file);
		~BitcoinExchange();

		float getRate(const std::string& date) const;
		
		BitcoinExchange& operator=(const BitcoinExchange& other);
};