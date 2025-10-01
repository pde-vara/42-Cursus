

#pragma once
#include "AForm.hpp"


class ShrubberyCreationForm : public AForm
{
	public:
		ShrubberyCreationForm(const std::string& target);
		ShrubberyCreationForm(const ShrubberyCreationForm& other);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
		~ShrubberyCreationForm();

	private:
		void executeAction() const;
};
