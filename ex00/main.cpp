#include <iostream>
#include "Bureaucrat.hpp"

int		main(void)
{
	{
		try {
			Bureaucrat	bur("Tylor", 1);

			std::cout << bur << std::endl;
			bur.decreaseGrade();
			std::cout << bur << std::endl;
			bur.increaseGrade();
			std::cout << bur << std::endl;
			bur.increaseGrade();
		} catch (std::exception const &e) {
			std::cout << "(default block)" << e.what() << std::endl;
		}
	}
}
