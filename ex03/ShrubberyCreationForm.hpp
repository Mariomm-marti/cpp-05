#ifndef CPP05_EX02_SHRUBBERYCREATIONFORM_H_
# define CPP05_EX02_SHRUBBERYCREATIONFORM_H_

# include <string>
# include <iostream>
# include "Form.hpp"

class Bureaucrat;

class ShrubberyCreationForm : public Form
{
private:
	std::string const	_target;

	ShrubberyCreationForm(void);

public:
	ShrubberyCreationForm(ShrubberyCreationForm &copy);
	ShrubberyCreationForm(std::string const &target);
	~ShrubberyCreationForm(void);

	ShrubberyCreationForm	&operator=(ShrubberyCreationForm &rhs);
	std::string const		&getTarget(void) const;

	void					execute(Bureaucrat const &executor) const;
};

#endif
