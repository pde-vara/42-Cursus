/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <pde-vara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 11:07:11 by pde-vara          #+#    #+#             */
/*   Updated: 2025/07/25 18:02:54 by pde-vara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(const std::string& name, const std::string& target, int gradeToSign, int gradeToExecute)
	: name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute), target(target)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooHighException();
}



	
AForm::AForm(const AForm& other)
	: name(other.name), isSigned(other.isSigned), gradeToSign(other.gradeToSign),
	gradeToExecute(other.gradeToExecute), target(other.target) {}

	
AForm& AForm::operator=(const AForm& other)
{
	if (this != &other)
		isSigned = other.isSigned; // name is const and can't be copied
	return *this;
}

AForm::~AForm() {}


std::string AForm::getName() const { return name; }

bool AForm::getIsSigned() const { return isSigned; }

int AForm::getGradeToSign() const { return gradeToSign; }

int AForm::getGradeToExecute() const { return gradeToExecute; }

const std::string& AForm::getTarget() const { return target; }


void AForm::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() > gradeToSign)
		throw GradeTooLowException();
	isSigned = true;
}

void AForm::execute(Bureaucrat const& executor) const
{
	if (!isSigned)
		throw FormNotSignedException();
	if (executor.getGrade() > gradeToExecute)
		throw GradeTooLowException();
	executeAction();  // calls the specific form action
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return "Grade too high!";
}


const char* AForm::GradeTooLowException::what() const throw()
{
	return "Grade too low!";
}

const char* AForm::FormNotSignedException::what() const throw()
{
	return "Form is not signed.";
}


std::ostream& operator<<(std::ostream& out, const AForm& b)
{
	out << "Form: " << b.getName()
		<< ", Signed: " << b.getIsSigned()
		<< ", Grade to sign: " << b.getGradeToSign()
		<< ", Grade to execute: " << b.getGradeToExecute()
		<< ", Target: " << b.getTarget();
	return out;
}
