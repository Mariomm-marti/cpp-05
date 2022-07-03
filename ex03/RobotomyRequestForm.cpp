#include <fstream>
#include <iostream>
#include <cstdlib>
#include <time.h>
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : Form("RobotomyRequestForm", 72, 45), _target("default target")
{
	std::cout << "[ROBOTOMYREQUESTFORM] Called default private constructor" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &copy) : Form(copy.getName(), copy.getSignGrade(), copy.getExecGrade()), _target(copy.getTarget())
{
	std::cout << "[ROBOTOMYREQUESTFORM] Called copy constructor" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string const &target) : Form("RobotomyRequestForm", 72, 45), _target(target)
{
	std::cout << "[ROBOTOMYREQUESTFORM] Called constructor" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << "[ROBOTOMYREQUESTFORM] Called destructor" << std::endl;
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(RobotomyRequestForm &rhs)
{
	std::cout << "[ROBOTOMYREQUESTFORM] Called assign operator, impossible to do anything" << std::endl;
	Form::operator=(rhs);
	return *this;
}

std::string const	&RobotomyRequestForm::getTarget(void) const
{
	return _target;
}

void				RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	std::cout << "[ROBOTOMYREQUESTFORM] Called execute" << std::endl;
	checkExecute(executor);
	srand(time(0));
	if (rand() % 2)
		std::cout << "* drilling noises * " << _target << " was converted!" << std::endl;
	else
		std::cout << "* drilling noises * failed to convert " << _target << std::endl;
}
