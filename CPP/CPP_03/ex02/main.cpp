/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <pde-vara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 18:26:44 by pde-vara          #+#    #+#             */
/*   Updated: 2025/06/05 17:40:49 by pde-vara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() 
{
	std::cout << "=== Creating Robots ===\n";
	ClapTrap clap("Clappy");
	ScavTrap scav("Scavy");
	FragTrap frag("Fraggy");

	std::cout << "\n=== Round 1: Attacks ===\n";
	clap.attack("Scavy");
	scav.takeDamage(3);

	scav.attack("Fraggy");
	frag.takeDamage(20);

	frag.attack("Clappy");
	clap.takeDamage(30);

	std::cout << "\n=== Round 2: Repairs and Special Abilities ===\n";
	clap.beRepaired(5);
	scav.beRepaired(10);
	scav.guardGate();
	frag.beRepaired(15);
	frag.highFivesGuys();

	std::cout << "\n=== Round 3: More Attacks ===\n";
	scav.attack("Clappy");
	clap.takeDamage(20);

	frag.attack("Scavy");
	scav.takeDamage(30);

	std::cout << "\n=== End of Battle ===\n";

	return 0;
}
