#ifndef CPP05_EX02_ROBOTOMYREQUESTFORM_H_
# define CPP05_EX02_ROBOTOMYREQUESTFORM_H_

# include <string>
# include <iostream>
# include "Form.hpp"

class Bureaucrat;

class RobotomyRequestForm : public Form
{
private:
	std::string const	_target;

	RobotomyRequestForm(void);

public:
	RobotomyRequestForm(RobotomyRequestForm &copy);
	RobotomyRequestForm(std::string const &target);
	~RobotomyRequestForm(void);

	RobotomyRequestForm	&operator=(RobotomyRequestForm &rhs);
	std::string const		&getTarget(void) const;

	void					execute(Bureaucrat const &executor) const;
};

#endif
