/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <pde-vara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 17:41:34 by pde-vara          #+#    #+#             */
/*   Updated: 2025/05/28 16:37:39 by pde-vara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

class Zombie 
{
	public:
		Zombie(std::string name);
		~Zombie();
		void announce( void );
		
	private:
		std::string _name;
};

Zombie* newZombie( std::string name ); //(heap)
void randomChump( std::string name );