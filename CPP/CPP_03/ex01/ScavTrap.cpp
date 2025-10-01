/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <pde-vara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 15:25:20 by pde-vara          #+#    #+#             */
/*   Updated: 2025/06/10 12:12:42 by pde-vara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ScavTrap.hpp"

ScavTrap::ScavTrap():ClapTrap("DefaultScav")
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap " << _name << " constructed by default!" << std::endl;
}
		
ScavTrap::ScavTrap(const std::string& name): ClapTrap(name)
{
	_hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
	std::cout << "ScavTrap " << _name << " has been constructed!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other): ClapTrap(other)
{
	std::cout << "ScavTrap " << _name << " copy constructed!" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
	}
	std::cout << "ScavTrap " << _name << " assigned!" << std::endl;
	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << _name << " has well been destroyed!" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (_hitPoints <= 0)
	{
		std::cout << "ScavTrap " << _name << " is dead and can't attack!" << std::endl;
		return;
	}
	if (_energyPoints <= 0)
	{
		std::cout << "ScavTrap " << _name << " has no energy and can't attack!" << std::endl;
		return;
	}
	_energyPoints--;
	std::cout << "ScavTrap " << _name << " attacks with stealth " << target
			  << ", causing " << _attackDamage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << _name << " is now in Gate keeper mode." << std::endl;
}