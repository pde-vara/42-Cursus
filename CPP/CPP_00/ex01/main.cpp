/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <pde-vara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 16:08:56 by pde-vara          #+#    #+#             */
/*   Updated: 2025/05/27 13:22:49 by pde-vara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "PhoneBook.hpp"
#include "Contact.hpp"

int main() 
{
	PhoneBook Annuaire;
	std::string command;
	while (1)
	{
		std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
		if (!std::getline(std::cin, command))
		{
			std::cout << "\nEOF received. Exiting." << std::endl;
			break;
		}
		if (command == "EXIT")
			break;
		else if (command == "SEARCH")
			Annuaire.searchContact();
		else if (command == "ADD")
			Annuaire.addContact();
		else
			std::cout << "Invalid command." << std::endl;
	}
	return (0);
}