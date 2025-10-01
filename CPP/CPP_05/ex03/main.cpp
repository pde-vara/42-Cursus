/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <pde-vara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 11:26:19 by pde-vara          #+#    #+#             */
/*   Updated: 2025/07/30 17:02:50 by pde-vara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


int main()
{
	Intern someRandomIntern;
	AForm* form;

	std::cout << "---- Valid form creation tests ----" << std::endl;

	form = someRandomIntern.makeForm("shrubbery creation", "Backyard");
	if (form) {
		Bureaucrat bob("Bob", 1);
		bob.signForm(*form);
		bob.executeForm(*form);
		delete form;
	}

	form = someRandomIntern.makeForm("robotomy request", "Bender");
	if (form) {
		Bureaucrat alice("Alice", 45); // Sufficient for Robotomy
		alice.signForm(*form);
		alice.executeForm(*form);
		delete form;
	}

	form = someRandomIntern.makeForm("presidential pardon", "Ford Prefect");
	if (form) {
		Bureaucrat zaphod("Zaphod", 1);
		zaphod.signForm(*form);
		zaphod.executeForm(*form);
		delete form;
	}

	std::cout << "\n---- Invalid form creation test ----" << std::endl;

	form = someRandomIntern.makeForm("coffee machine", "Office");
	if (!form) {
		std::cout << "Invalid form test passed.\n";
	}

	return 0;
}
