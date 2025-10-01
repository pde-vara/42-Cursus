/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <pde-vara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 14:35:21 by pde-vara          #+#    #+#             */
/*   Updated: 2025/07/30 16:57:13 by pde-vara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& other) { (void)other; }

Intern& Intern::operator=(const Intern& other) { (void)other; return *this; }

Intern::~Intern() {}



AForm* Intern::makeForm(const std::string& formName, const std::string& formTarget)
{
	const std::string names[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};
	
	for (int i = 0; i < 3; ++i)
	{
		if (formName == names[i])
		{
			std::cout << "Intern creates " << formName << std::endl;
			switch (i)
			{
				case 0: return new ShrubberyCreationForm(formTarget);
				case 1: return new RobotomyRequestForm(formTarget);
				case 2: return new PresidentialPardonForm(formTarget);
			}
		}
	}
	std::cerr << "Intern couldn't find the form: " << formName << std::endl;
	return NULL;
}

