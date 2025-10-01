/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <pde-vara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 14:55:25 by pde-vara          #+#    #+#             */
/*   Updated: 2025/06/10 15:08:50 by pde-vara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(): ClapTrap("Default_clap_name"), FragTrap(), ScavTrap(), _name("Default")
{
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;
	std::cout << "DiamondTrap " << _name << " constructed by default!" << std::endl;
}
		
DiamondTrap::DiamondTrap(const std::string& name): ClapTrap(name + "_clap_name"), FragTrap(), ScavTrap(), _name(name)
{
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;
	std::cout << "DiamondTrap " << _name << " constructed!" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other): ClapTrap(other), FragTrap(other), ScavTrap(other)
{
	std::cout << "DiamondTrap " << _name << " copy constructed!" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
	}
	std::cout << "DiamondTrap " << _name << " assigned!" << std::endl;
	return *this;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << _name << " has well been destroyed!" << std::endl;
}



void DiamondTrap::whoAmI() 
{
    std::cout << "I am " << _name << " and my ClapTrap name is " << ClapTrap::_name << std::endl;
}