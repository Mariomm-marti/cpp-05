#ifndef CPP05_EX01_FORM_H_
# define CPP05_EX01_FORM_H_

# include <string>
# include <iostream>

class Bureaucrat;

class Form
{
private:
	std::string const	_name;
	size_t const		_signGrade;
	size_t const		_execGrade;
	bool				_signed;

	Form(void);

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
	class UnsignedFormException : public std::exception
	{
	public:
		char	*what(void) const throw();
	};

	Form(Form &copy);
	Form(std::string const &name, size_t const &signGrade, size_t const &execGrade);
	virtual ~Form(void);

	Form				&operator=(Form &rhs);
	std::string const	&getName(void) const;
	size_t const		&getSignGrade(void) const;
	size_t const		&getExecGrade(void) const;
	bool const			&isSigned(void) const;

	void				beSigned(Bureaucrat const &signer);
	void				checkExecute(Bureaucrat const &executor) const;
	virtual void		execute(Bureaucrat const &executor) const = 0;
};

std::ostream	&operator<<(std::ostream &out, Form const &f);

#endif
