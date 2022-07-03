#ifndef CPP05_EX02_PRESIDENTIALPARDONFORM_H_
# define CPP05_EX02_PRESIDENTIALPARDONFORM_H_

# include <string>
# include <iostream>
# include "Form.hpp"

class Bureaucrat;

class PresidentialPardonForm : public Form
{
private:
	std::string const	_target;

	PresidentialPardonForm(void);

public:
	PresidentialPardonForm(PresidentialPardonForm &copy);
	PresidentialPardonForm(std::string const &target);
	~PresidentialPardonForm(void);

	PresidentialPardonForm	&operator=(PresidentialPardonForm &rhs);
	std::string const		&getTarget(void) const;

	void					execute(Bureaucrat const &executor) const;
};

#endif
