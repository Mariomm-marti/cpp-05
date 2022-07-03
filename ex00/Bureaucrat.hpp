#ifndef CPP05_EX00_BUREAUCRAT_H_
# define CPP05_EX00_BUREAUCRAT_H_

# include <string>

class Bureaucrat
{
private:
	std::string const	_name;
	size_t				_grade;

	Bureaucrat(void);
public:
	class GradeTooHighException : public std::exception
	{
	public:
		char	*what(void) const throw();
	};
	class GradeTooLowException : public std::exception
	{
	public:
		char	*what(void) const throw();
	};

	Bureaucrat(Bureaucrat &copy);
	Bureaucrat(std::string const &name, size_t const &grade);
	~Bureaucrat(void);

	Bureaucrat			&operator=(Bureaucrat &rhs);
	std::string const	&getName(void) const;
	size_t const		&getGrade(void) const;
	void				increaseGrade(void);
	void				decreaseGrade(void);
};

std::ostream	&operator<<(std::ostream &out, Bureaucrat const &b);

#endif
