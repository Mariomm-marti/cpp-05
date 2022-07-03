#include <iostream>
#include "Bureaucrat.hpp"

int		main(void)
{
	try {
		Bureaucrat	tyler("Tyler", 20);
		//Form		form("42A", 10, 5);
		Form		form("42A", 25, 5);

		form.beSigned(tyler);
		tyler.signForm(form);
		form.beSigned(tyler);
		std::cout << form << std::endl;
		std::cout << tyler << std::endl;
	} catch (std::exception const &e) {
		std::cout << e.what() << std::endl;
	}
}
