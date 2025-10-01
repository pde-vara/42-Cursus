/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <pde-vara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 16:33:11 by pde-vara          #+#    #+#             */
/*   Updated: 2025/05/27 17:25:50 by pde-vara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() 
{
	totalContacts = 0;
	nextIndex = 0;
}

void PhoneBook::addContact()
{
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string darkestSecret;
	
	std::cout << "Enter First Name: ";
	std::getline(std::cin, firstName);
	std::cout << "Enter Last Name: ";
	std::getline(std::cin, lastName);
	std::cout << "Enter Nickname: ";
	std::getline(std::cin, nickname);
	std::cout << "Enter Phone Number: ";
	std::getline(std::cin, phoneNumber);
	std::cout << "Enter Darkest Secret(vasy bebou): ";
	std::getline(std::cin, darkestSecret);

	if (firstName.empty() || lastName.empty() || nickname.empty() || phoneNumber.empty() || darkestSecret.empty())
	{
		std::cout << "Error: all fields must be filled!" << std::endl;
		return;
	}

	contact[nextIndex].setContact(firstName, lastName, nickname, phoneNumber, darkestSecret);
	nextIndex = (nextIndex + 1) % 8;
	
	if (totalContacts < 8)
		totalContacts++;
	
	std::cout << "Contact added successfully!" << std::endl;
}

void PhoneBook::searchContact()
{
	if (totalContacts == 0) 
	{
		std::cout << "PhoneBook is empty!" << std::endl;
		return;
	}
	std::cout << "|  Index   |First Name| Last Name| Nickname |" << std::endl;
	for (int i = 0; i < totalContacts; i++)
	{
		contact[i].displayShort(i);
	}
	std::cout << "Enter the index of the contact to display: ";
	std::string input;
	std::getline(std::cin, input);

	if (input.length() != 1 || input[0] < '0' || input[0] > '7')
	{
		std::cout << "Invalid index." << std::endl;
		return;
	}
	
	int index = input[0] - '0';
	if (index >= totalContacts)
	{
		std::cout << "Index out of range." << std::endl;
		return;
	}
	contact[index].displayFull();
}