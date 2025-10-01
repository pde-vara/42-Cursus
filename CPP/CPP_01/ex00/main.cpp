/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <pde-vara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 17:44:55 by pde-vara          #+#    #+#             */
/*   Updated: 2025/06/03 16:42:06 by pde-vara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	randomChump("StackZombie");

	Zombie *ptr = newZombie("HeapZombie");
	ptr->announce();
	delete ptr;
	
	return (0);
}
