/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <pde-vara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 17:19:29 by pde-vara          #+#    #+#             */
/*   Updated: 2025/09/02 16:46:22 by pde-vara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <iostream>
#include <cstdlib> // for rand() and srand()
#include <ctime>

Base* generate();
void identify(Base* p);
void identify(Base& p);

int main() {
	std::srand(std::time(0));
    Base* ptr = generate();

    std::cout << "Identifying using pointer: ";
    identify(ptr);

    std::cout << "Identifying using reference: ";
    identify(*ptr);

    delete ptr;
    return 0;
}
