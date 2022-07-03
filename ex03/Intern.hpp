#ifndef CPP05_EX03_INTERN_H_
# define CPP05_EX03_INTERN_H_

# include <string>
# include "Form.hpp"

class Intern
{
public:
	class UnknownFormException : public std::exception
	{
	public:
		char	*what(void) const throw();
	};
	Intern(void);
	Intern(Intern &copy);
	~Intern(void);

	Intern	&operator=(Intern &rhs);
	Form	*makeForm(std::string const &type, std::string const &target) throw(Intern::UnknownFormException);
};

#endif
