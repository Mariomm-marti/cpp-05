#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int		main(void)
{
	try {
		Bureaucrat	tyler("Tyler", 149);
		Form		*form = new ShrubberyCreationForm("dylan");
		Form		*form2 = new RobotomyRequestForm("markus");
		Form		*form3 = new PresidentialPardonForm("alan");

		form->beSigned(tyler);
		form->execute(tyler);
		form2->beSigned(tyler);
		form2->execute(tyler);
		tyler.executeForm(*form3);
		delete form;
		delete form2;
		delete form3;
	} catch (std::exception const &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		Bureaucrat	tyler("Tyler", 145);
		Form		*form = new ShrubberyCreationForm("dylan");
		Form		*form2 = new RobotomyRequestForm("markus");
		Form		*form3 = new PresidentialPardonForm("alan");

		form->beSigned(tyler);
		form->execute(tyler);
		form2->beSigned(tyler);
		form2->execute(tyler);
		form3->beSigned(tyler);
		tyler.executeForm(*form3);
		delete form;
		delete form2;
		delete form3;
	} catch (std::exception const &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		Bureaucrat	tyler("Tyler", 1);
		Form		*form = new ShrubberyCreationForm("dylan");
		Form		*form2 = new RobotomyRequestForm("markus");
		Form		*form3 = new PresidentialPardonForm("alan");

		form->beSigned(tyler);
		form->execute(tyler);
		form2->beSigned(tyler);
		form2->execute(tyler);
		tyler.signForm(*form3);
		tyler.executeForm(*form3);
		delete form;
		delete form2;
		delete form3;
	} catch (std::exception const &e) {
		std::cout << e.what() << std::endl;
	}
}
