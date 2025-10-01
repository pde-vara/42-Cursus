



#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string name;
		bool isSigned;
		const int gradeToSign;
		const int gradeToExecute;
		const std::string target;

	public:
		AForm(const std::string& name, const std::string& target, int gradeToSign, int gradeToExecute);
		AForm(const AForm& other);
		AForm& operator=(const AForm& other);
		virtual ~AForm();

		void beSigned(const Bureaucrat& b);
		virtual void execute(Bureaucrat const & executor) const;

		virtual void executeAction() const = 0;

		std::string getName() const;
		bool getIsSigned() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;
		const std::string& getTarget() const;


		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw();
		};

		class FormNotSignedException : public std::exception
		{
			public:
				const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& out, const AForm& b);