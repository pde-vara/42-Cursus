


#pragma once
#include "AForm.hpp"
#include <cstdlib>

class RobotomyRequestForm : public AForm
{
	public:
		RobotomyRequestForm(const std::string& target);
		~RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm& other);
		RobotomyRequestForm& operator=(const RobotomyRequestForm& other);

	private:
		void executeAction() const;
};