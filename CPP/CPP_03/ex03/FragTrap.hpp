



#pragma once

#include <string>
#include <iostream>
#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	public:
		FragTrap();
		FragTrap(const std::string& name);
		FragTrap(const FragTrap& other);
		FragTrap& operator=(const FragTrap& other);
		~FragTrap();

		void highFivesGuys();
		// void attack(const std::string& target); // override pour afficher les points d'attaque
};
