/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <pde-vara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 11:26:19 by pde-vara          #+#    #+#             */
/*   Updated: 2025/07/24 12:02:12 by pde-vara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"


int main()
{
    try
    {
        Bureaucrat alice("Alice", 40);
        Form report("Monthly Report", 50, 30);

        std::cout << report << std::endl;

        // Successful signing
        alice.signForm(report);
        std::cout << report << std::endl;

        Bureaucrat bob("Bob", 100);
        Form classified("Top Secret", 50, 30);

        std::cout << classified << std::endl;

        // Fails to sign due to low grade
        bob.signForm(classified);
        std::cout << classified << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Unhandled exception: " << e.what() << std::endl;
    }
    return 0;
}