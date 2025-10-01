/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <pde-vara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 11:39:41 by pde-vara          #+#    #+#             */
/*   Updated: 2025/05/29 11:31:31 by pde-vara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
	_name = "unamed";
}
Zombie::Zombie(std::string name)
{
	_name = name;
	std::cout << "Zombie " << _name << " created." << std::endl;
}

Zombie::~Zombie()
{
	std::cout << "Zombie " << _name << " destroyed." << std::endl;
}

void Zombie::announce()
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name)
{
	_name = name;
	std::cout << "Zombie " << _name << " created." << std::endl;
}
