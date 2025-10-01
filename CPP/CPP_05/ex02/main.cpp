/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <pde-vara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 11:26:19 by pde-vara          #+#    #+#             */
/*   Updated: 2025/07/25 19:56:07 by pde-vara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


int main()
{
	try
	{
		Bureaucrat bob("Bob", 1); // Highest grade, can sign & execute everything
		Bureaucrat jim("Jim", 150); // Lowest grade, likely to fail signing/executing

		ShrubberyCreationForm shrub("home");
		RobotomyRequestForm robo("Marvin");
		PresidentialPardonForm pardon("Arthur Dent");

		std::cout << "--- Initial Forms ---" << std::endl;
		std::cout << shrub << std::endl;
		std::cout << robo << std::endl;
		std::cout << pardon << std::endl;

		// Try executing unsigned form - should throw
		std::cout << "--- Executing unsigned Shrubbery ---" << std::endl;
		try 
		{
			bob.executeForm(shrub);
			jim.executeForm(pardon);
		}
		catch (const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}

		// Jim tries to sign form - should fail due to low grade
		std::cout << "--- Jim tries to sign RobotomyRequestForm ---" << std::endl;
		try
		{
			jim.signForm(robo);
		}
		catch (const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}

		// Bob signs all forms
		std::cout << "--- Bob signs all forms ---" << std::endl;
		bob.signForm(shrub);
		bob.signForm(robo);
		bob.signForm(pardon);

		// Output after signing
		std::cout << shrub << std::endl;
		std::cout << robo << std::endl;
		std::cout << pardon << std::endl;

		// Jim tries to execute - should fail
		std::cout << "--- Jim tries to execute ShrubberyCreationForm ---" << std::endl;
		try
		{
			jim.executeForm(shrub);
		}
		catch (const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}

		// Bob executes all forms - should succeed
		std::cout << "--- Bob executes all forms ---" << std::endl;
		bob.executeForm(shrub);
		bob.executeForm(robo);
		bob.executeForm(pardon);

	}
	catch (const std::exception& e)
	{
		std::cerr << "Unexpected exception: " << e.what() << std::endl;
    }

    return 0;
}