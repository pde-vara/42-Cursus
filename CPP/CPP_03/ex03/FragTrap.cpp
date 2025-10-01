/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <pde-vara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 17:21:24 by pde-vara          #+#    #+#             */
/*   Updated: 2025/06/10 15:11:42 by pde-vara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "FragTrap.hpp"

FragTrap::FragTrap():ClapTrap("DefaultFrag")
{
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap " << _name << " built!" << std::endl;
}
		
FragTrap::FragTrap(const std::string& name): ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap " << _name << " built!" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other): ClapTrap(other)
{
	std::cout << "FragTrap " << _name << " copy constructed!" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
	}
	std::cout << "FragTrap " << _name << " assigned!" << std::endl;
	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << _name << " is destroyed!" << std::endl;
}

// void FragTrap::attack(const std::string& target)
// {
// 	if (_energyPoints > 0 && _hitPoints > 0)
// 	{
// 		_energyPoints--;
// 		std::cout	<< "FragTrap " << _name << "deadly attacks " << target
// 					<< ", causing " << _attackDamage << " points of damage!" << std::endl;
// 	}
// 		else
// 	{
// 		std::cout << "FragTrap " << _name << " has no energy or is dead and can't attack!" << std::endl;
// 	}
// }

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << _name << " requests a high five! ✋" << std::endl;
}