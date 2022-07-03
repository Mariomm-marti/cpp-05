#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

int		main(void)
{
	try {
		Bureaucrat	tyler("Tyler", 149);
		Form		*form = new ShrubberyCreationForm("dylan");

		form->beSigned(tyler);
		form->execute(tyler);
	} catch (std::exception const &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		Bureaucrat	tyler("Tyler", 145);
		Form		*form = new ShrubberyCreationForm("dylan");

		form->beSigned(tyler);
		form->execute(tyler);
	} catch (std::exception const &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		Bureaucrat	tyler("Tyler", 1);
		Form		*form = new ShrubberyCreationForm("dylan");

		form->beSigned(tyler);
		form->execute(tyler);
	} catch (std::exception const &e) {
		std::cout << e.what() << std::endl;
	}
}
