/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <pde-vara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 18:26:44 by pde-vara          #+#    #+#             */
/*   Updated: 2025/06/10 12:32:08 by pde-vara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"


int main()
{
	ScavTrap a("Bender");
	ScavTrap b("Scavy");

	std::cout << "\n--- ROUND 1 ---\n" << std::endl;
	a.attack("Scavy");
	b.takeDamage(20); // Hardcoded based on ScavTrap's attackDamage

	b.attack("Bender");
	a.takeDamage(20);

	std::cout << "\n--- ROUND 2 ---\n" << std::endl;

	a.beRepaired(15);
	b.beRepaired(10);

	std::cout << "\n--- ROUND 3 ---\n" << std::endl;

	a.attack("Scavy");
	b.takeDamage(20);

	b.attack("Bender");
	a.takeDamage(20);

	std::cout << "\n--- GATE KEEPER MODE ---\n" << std::endl;

	a.guardGate();
	b.guardGate();

	std::cout << "\n--- END OF BATTLE ---\n" << std::endl;

	return 0;
}