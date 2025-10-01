/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <pde-vara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 16:02:39 by pde-vara          #+#    #+#             */
/*   Updated: 2025/05/29 11:42:32 by pde-vara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main()
{
	std::string str = "HI THIS IS BRAIN";
	std::string *ptr = &str;
	std::string &ref = str;

	std::cout << "Address of str		: " << &str << std::endl;
	std::cout << "Address of str		: " << ptr << std::endl;
	std::cout << "Address of str		: " << &ref << std::endl;

	std::cout << "Value of str		: " << str << std::endl;
	std::cout << "Value of str		: " << *ptr << std::endl;
	std::cout << "Value of str		: " << ref << std::endl;
}