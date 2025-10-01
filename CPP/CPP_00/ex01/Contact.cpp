/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <pde-vara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 16:28:00 by pde-vara          #+#    #+#             */
/*   Updated: 2025/05/27 16:49:30 by pde-vara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "Contact.hpp"

void Contact::setContact(std::string fn, std::string ln, std::string nn, std::string phone, std::string secret)
{
	firstName = fn;
	lastName = ln;
	nickname = nn;
	phoneNumber = phone;
	darkestSecret = secret;
}

std::string truncate(const std::string& str) 
{
	if (str.length() > 10)
		return str.substr(0, 9) + ".";
	return str;
}

void Contact::displayShort(int index) const 
{
	std::cout << "|" << std::setw(10) << index;
	std::cout << "|" << std::setw(10) << truncate(firstName);
	std::cout << "|" << std::setw(10) << truncate(lastName);
	std::cout << "|" << std::setw(10) << truncate(nickname);
	std::cout << "|" << std::endl;
}

void Contact::displayFull() const 
{
	std::cout << "First Name: " << firstName << std::endl;
	std::cout << "Last Name: " << lastName << std::endl;
	std::cout << "Nickname: " << nickname << std::endl;
	std::cout << "Phone Number: " << phoneNumber << std::endl;
	std::cout << "Darkest Secret: " << darkestSecret << std::endl;
}
