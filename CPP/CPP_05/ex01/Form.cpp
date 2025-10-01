/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <pde-vara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 11:07:11 by pde-vara          #+#    #+#             */
/*   Updated: 2025/07/30 14:33:16 by pde-vara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute)
	: name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooHighException();
}

	
Form::Form(const Form& other)
	: name(other.name), isSigned(other.isSigned), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute) {}

	
Form& Form::operator=(const Form& other)
{
	if (this != &other)
	{
		isSigned = other.isSigned; // name is const and can't be copied
	}
	return *this;
}

Form::~Form() {}


std::string Form::getName() const { return name; }

bool Form::getIsSigned() const { return isSigned; }

int Form::getGradeToSign() const { return gradeToSign; }

int Form::getGradeToExecute() const { return gradeToExecute; }


void Form::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() > gradeToSign)
		throw GradeTooLowException();
	isSigned = true;
}



const char* Form::GradeTooHighException::what() const throw()
{
	return "Form grade too high!";
}


const char* Form::GradeTooLowException::what() const throw()
{
	return "Form grade too low!";
}

std::ostream& operator<<(std::ostream& out, const Form& b)
{
	out << "Form " << b.getName()
		<< ", Signed: " << (b.getIsSigned() ? "true" : "false")
		<< ", Grade required to sign: " << b.getGradeToSign()
		<< ", Grade required to execute: " << b.getGradeToExecute();
	return out;
}
