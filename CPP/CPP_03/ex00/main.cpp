/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <pde-vara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 18:26:44 by pde-vara          #+#    #+#             */
/*   Updated: 2025/06/05 15:08:43 by pde-vara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"


int main()
{
	ClapTrap a("Bender");
	ClapTrap b("Clappy");

	std::cout << "\n--- ROUND 1 ---\n" << std::endl;
	a.attack("Clappy");
	b.takeDamage(3);

	std::cout << "\n--- ROUND 2 ---\n" << std::endl;
	b.attack("Bender");
	a.takeDamage(3);

	std::cout << "\n--- ROUND 3 ---\n" << std::endl;
	a.attack("Clappy");
	b.takeDamage(3);

	std::cout << "\n--- ROUND 4 ---\n" << std::endl;
	b.beRepaired(2); // Clappy heals
	a.attack("Clappy");
	b.takeDamage(3);

	std::cout << "\n--- ROUND 5 ---\n" << std::endl;
	b.attack("Bender");
	a.takeDamage(3);

	std::cout << "\n--- ROUND 6 ---\n" << std::endl;
	a.attack("Clappy");
	b.takeDamage(3); // Should die here if HP hits 0

	std::cout << "\n--- END OF BATTLE ---\n" << std::endl;

	return 0;
}