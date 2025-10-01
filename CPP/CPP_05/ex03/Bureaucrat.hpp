


#pragma once

#include <fstream>
#include <iostream>
#include <string>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
	private:
		const std::string name;
		int grade;

	public:
		Bureaucrat(const std::string& name, int grade);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other);
		virtual ~Bureaucrat();

		const std::string& getName() const;
		int getGrade() const;

		void incrementGrade(); // grade--
		void decrementGrade(); // grade++

		void signForm(AForm& f);
		void executeForm(const AForm& form) const;
		

	class GradeTooHighException : public std::exception
	{
		const char* what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& b);