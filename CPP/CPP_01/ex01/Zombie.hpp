
#pragma once

#include <string>
#include <iostream>

class Zombie 
{
	public:
		Zombie(); // default constructor
		Zombie(std::string name);
		~Zombie();

		void announce();
		void setName(std::string name);
		
	private:
		std::string _name;
};

Zombie* zombieHorde(int N, std::string name);