




#pragma once

#include <fstream>
#include <iostream>
#include <string>
#include "AForm.hpp"

class AForm;

class Intern
{
	public:
		Intern();
		Intern(const Intern& other);
		Intern& operator=(const Intern& other);
		~Intern();

		AForm *makeForm(const std::string& formName, const std::string& formTarget);
};
