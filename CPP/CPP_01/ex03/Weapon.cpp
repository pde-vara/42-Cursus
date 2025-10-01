/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <pde-vara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 16:28:50 by pde-vara          #+#    #+#             */
/*   Updated: 2025/05/29 12:36:02 by pde-vara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(const std::string& type)
{
	_type = type;
}

const std::string& Weapon::getType() const
{
	return (_type);
}

void Weapon::setType(const std::string& newType)
{
	_type = newType;
}