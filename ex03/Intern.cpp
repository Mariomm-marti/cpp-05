#include <iostream>
#include "Intern.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

char	*Intern::UnknownFormException::what(void) const throw()
{
	return (char *)"[EX][INTERN] Impossible to identify form";
}

Intern::Intern(void)
{
	std::cout << "[INTERN] New intern spawned!" << std::endl;
}

Intern::Intern(Intern &copy)
{
	(void)copy;
	std::cout << "[INTERN] Copy constructor called... For nothing" << std::endl;
}

Intern::~Intern(void)
{
	std::cout << "[INTERN] Destructor called" << std::endl;
}

Intern	&Intern::operator=(Intern &rhs)
{
	(void)rhs;
	std::cout << "[INTERN] Assignment operator called... For nothing" << std::endl;
	return *this;
}

Form	*Intern::makeForm(std::string const &type, std::string const &target) throw(Intern::UnknownFormException)
{
	std::string	formNames[3] = { "shrubbery", "robotomy", "presidential" };
	Form		*formRefs[3] = { new ShrubberyCreationForm(target), new RobotomyRequestForm(target), new PresidentialPardonForm(target) };
	ssize_t		rightForm = -1;

	for (size_t i = 0; i < 3; i++)
		if (formNames[i] == type)
			rightForm = i;
		else
			delete formRefs[i];
	if (rightForm != -1)
		return formRefs[rightForm];
	throw Intern::UnknownFormException();
}
