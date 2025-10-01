/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <pde-vara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 18:26:41 by pde-vara          #+#    #+#             */
/*   Updated: 2025/06/10 12:43:46 by pde-vara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): _name("Defaut"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap " << _name << " constructed!" << std::endl;
}
		
ClapTrap::ClapTrap(const std::string& name): _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap " << _name << " constructed!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
	*this = other;
	std::cout << "ClapTrap " << _name << " copy constructed!" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	if (this != &other)
	{
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
	}
	std::cout << "ClapTrap " << _name << " assigned!" << std::endl;
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << _name << " destroyed!" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	(void)_attackDamage;
	
	if (_energyPoints <= 0)
	{
		std::cout << "ClapTrap " << _name << " has no energy and can't attack!" << std::endl;
		return;
	}
	if (_hitPoints <= 0)
	{
		std::cout << "ClapTrap " << _name << " is dead and can't attack!" << std::endl;
		return;
	}
	_energyPoints--;
	std::cout << "ClapTrap " << _name << " attacks " << target << std::endl;
}
	
void ClapTrap::takeDamage(unsigned int amount)
{
	if (amount <= 0)
	{
		std::cout << "ClapTrap " << _name << " takes 0 damage!" << std::endl;
		return;
	}
	if (_hitPoints <= 0)
	{
		std::cout << "ClapTrap " << _name << " is already dead." << std::endl;
		return;
	}
	_hitPoints -= amount;
	if (_hitPoints <= 0)
	{
		_hitPoints = 0;
		std::cout << "ClapTrap " << _name << " took " << amount << " damage and died!" << std::endl;
	}
	else
	{
		std::cout << "ClapTrap " << _name << " takes " << amount << " damage, now at " << _hitPoints << " HP." << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_hitPoints <= 0 || _energyPoints <= 0)
	{
		std::cout << "ClapTrap " << _name << " can't repair (dead or no energy)." << std::endl;
		return;
	}
	_energyPoints--;
	int heal = static_cast<int>(amount);
	int maxHP = 100000; // Atbitrary, can be int max

	if (_hitPoints + heal > maxHP)
	{
		heal = maxHP - _hitPoints;
		_hitPoints = maxHP;
	}
	else
	{
		_hitPoints += heal;
	}
	std::cout << "ClapTrap " << _name << " heals " << heal << ", now at " << _hitPoints << " HP." << std::endl;
}
