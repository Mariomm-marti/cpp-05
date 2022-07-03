#include <iostream>
#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int		main(void)
{
	Intern		a;
	Bureaucrat	signer("Manuel", 1);

	Form	*form = a.makeForm("presidential", "Lorem");
	signer.signForm(*form);
	signer.executeForm(*form);
	delete form;
}
