/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <pde-vara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 11:39:33 by pde-vara          #+#    #+#             */
/*   Updated: 2025/06/03 16:43:11 by pde-vara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"


int main()
{
	int N = 4;
	Zombie* horde = zombieHorde(N, "Walker");
	for (int i = 0; i < N; ++i)
		horde[i].announce();

	delete[] horde;
	return 0;
}
