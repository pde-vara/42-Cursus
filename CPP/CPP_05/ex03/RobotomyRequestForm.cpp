/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <pde-vara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 12:50:53 by pde-vara          #+#    #+#             */
/*   Updated: 2025/07/25 18:05:22 by pde-vara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
	: AForm("RobotomyRequestForm", target, 72, 45) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
	: AForm(other) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	AForm::operator=(other);
	return *this;
}


void RobotomyRequestForm::executeAction() const {
    std::cout << "* drilling noises *" << std::endl;
    if (std::rand() % 2)
        std::cout << getTarget() << " has been robotomized successfully!" << std::endl;
    else
        std::cout << "Robotomy failed on " << getTarget() << "." << std::endl;
}
