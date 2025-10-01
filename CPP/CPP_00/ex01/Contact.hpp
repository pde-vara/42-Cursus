/* ************************************************************************** */
/*		                                                                        */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <pde-vara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 16:06:51 by pde-vara          #+#    #+#             */
/*   Updated: 2025/05/26 18:05:10 by pde-vara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>


class Contact
{
	public:
		std::string firstName;
		std::string lastName;
		std::string nickname;
		std::string phoneNumber;
		std::string darkestSecret;
		void setContact(std::string firstName, std::string lastName, std::string nickname, std::string phoneNumber,
						std::string darkestSecret);
		void displayShort(int index) const;
		void displayFull() const;
	
	private:
		
};
