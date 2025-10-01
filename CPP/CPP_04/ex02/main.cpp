/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <pde-vara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 15:22:09 by pde-vara          #+#    #+#             */
/*   Updated: 2025/06/11 17:47:25 by pde-vara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main() 
{
	// Create an array of Animal pointers to demonstrate polymorphism
	const Animal* animals[4];
	
	// animals[3] = new Animal();
	// animals[3]->makeSound();
	
	// Fill half the array with Dogs
	for (int i = 0; i < 2; i++) {
		animals[i] = new Dog();
	}

	// Fill the other half of the array with Cats
	for (int i = 2; i < 4; i++) {
		animals[i] = new Cat();
	}

	// Test making sounds to demonstrate polymorphism
	for (int i = 0; i < 4; i++) {
		animals[i]->makeSound();
	}

	// Clean up allocated memory
	for (int i = 0; i < 4; i++) {
		delete animals[i];
	}
	
	// Create separate instances of Dog and Cat
	Dog originalDog;
	Cat originalCat;
	
	// Test copying by creating copies of the original Dog and Cat
	Dog dogCopy(originalDog);
	Cat catCopy(originalCat);

	// Demonstrate that copies work correctly
	dogCopy.makeSound();
	catCopy.makeSound();

	return 0;
}