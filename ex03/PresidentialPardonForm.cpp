#include <fstream>
#include <iostream>
#include <cstdlib>
#include <time.h>
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : Form("PresidentialPardonForm", 25, 5), _target("default target")
{
	std::cout << "[PRESIDENTIALPARDONFORM] Called default private constructor" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &copy) : Form(copy.getName(), copy.getSignGrade(), copy.getExecGrade()), _target(copy.getTarget())
{
	std::cout << "[PRESIDENTIALPARDONFORM] Called copy constructor" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string const &target) : Form("PresidentialPardonForm", 25, 5), _target(target)
{
	std::cout << "[PRESIDENTIALPARDONFORM] Called constructor" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	std::cout << "[PRESIDENTIALPARDONFORM] Called destructor" << std::endl;
}

PresidentialPardonForm	&PresidentialPardonForm::operator=(PresidentialPardonForm &rhs)
{
	std::cout << "[PRESIDENTIALPARDONFORM] Called assign operator, impossible to do anything" << std::endl;
	Form::operator=(rhs);
	return *this;
}

std::string const	&PresidentialPardonForm::getTarget(void) const
{
	return _target;
}

void				PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	std::cout << "[PRESIDENTIALPARDONFORM] Called execute" << std::endl;
	checkExecute(executor);
	std::cout << _target << " has been pardoned by Zafod Beeblebrox" << std::endl;
}
