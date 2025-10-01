/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <pde-vara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 16:34:36 by pde-vara          #+#    #+#             */
/*   Updated: 2025/06/02 15:20:11 by pde-vara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {}

void Harl::debug(void)
{
	std::cout	<< "[ DEBUG ]\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!\n"
				<< std::endl;
}

void Harl::info(void)
{
	std::cout	<< "[ INFO ]\nI cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n"
				<< std::endl;
}

void Harl::warning(void)
{
	std::cout	<< "[ WARNING ]\nI think I deserve to have some extra bacon for free. I've been coming for years, whereas you started working here just last month.\n"
				<< std::endl;
}

void Harl::error(void)
{
	std::cout	<< "[ ERROR ]\nThis is unacceptable! I want to speak to the manager now.\n"
				<< std::endl;
}

void Harl::complain(std::string level)
{
	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*functions[])() = 
	{
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};

	int index = -1;
	for (int i = 0; i < 4; ++i)
	{
		if (levels[i] == level)
		{
			index = i;
			break;
		}
	}

	switch (index)
	{
	case 0:
		(this->*functions[0])();
	case 1:
		(this->*functions[1])();
	case 2:
		(this->*functions[2])();
	case 3:
		(this->*functions[3])();
		break;
	default:
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}
