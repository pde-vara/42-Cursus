/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <pde-vara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 16:28:17 by pde-vara          #+#    #+#             */
/*   Updated: 2025/05/29 14:07:51 by pde-vara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "HumanA.hpp"

HumanA::HumanA(const std::string& name, Weapon& weapon): _weapon(weapon)
{
	_name = name;
}

void HumanA::attack() const
{
	std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
}