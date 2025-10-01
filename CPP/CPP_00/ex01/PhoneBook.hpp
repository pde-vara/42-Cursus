/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <pde-vara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 16:32:27 by pde-vara          #+#    #+#             */
/*   Updated: 2025/05/27 16:55:42 by pde-vara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Contact.hpp"


class PhoneBook 
{
	public:
		PhoneBook();
		void addContact();
		void searchContact();

	private:
		Contact contact[8];
		int totalContacts;
		int nextIndex;

};
