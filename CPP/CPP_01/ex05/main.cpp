/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <pde-vara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 16:34:10 by pde-vara          #+#    #+#             */
/*   Updated: 2025/06/02 14:16:42 by pde-vara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv) 
{
	if (argc != 2)
	{
		std::cerr << "Usage: ./harl <level>" << std::endl;
		return 1;
	}
	
	Harl harl;

	harl.complain(argv[1]);
	
	return 0;
}