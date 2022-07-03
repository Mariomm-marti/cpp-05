#include <iostream>
#include <string>
#include "Bureaucrat.hpp"
#include "Form.hpp"

char	*Form::GradeTooHighException::what(void) const throw()
{
	return (char *)"[EX][FORM] Used grade was too high";
}

char	*Form::GradeTooLowException::what(void) const throw()
{
	return (char *)"[EX][FORM] Used grade was too low";
}

char	*Form::UnsignedFormException::what(void) const throw()
{
	return (char *)"[EX][FORM] The form is not signed";
}

Form::Form(void) : _name("1A"), _signGrade(1), _execGrade(1), _signed(false)
{
	std::cout << "[FORM] Called default constructor" << std::endl;
}

Form::Form(Form &copy) : _name(copy.getName()), _signGrade(copy.getSignGrade()), _execGrade(copy.getExecGrade())
{
	std::cout << "[FORM] Called copy constructor" << std::endl;
	*this = copy;
}

Form::Form(std::string const &name, size_t const &signGrade, size_t const &execGrade) : _name(name), _signGrade(signGrade), _execGrade(execGrade), _signed(false)
{
	std::cout << "[FORM] Called custom constructor" << std::endl;
	if (signGrade < 1 || execGrade < 1)
		throw Form::GradeTooHighException();
	if (signGrade > 150 || execGrade > 150)
		throw Form::GradeTooLowException();
}

Form::~Form(void)
{
	std::cout << "[FORM] Called destructor" << std::endl;
}

Form	&Form::operator=(Form &rhs)
{
	std::cout << "[FORM] Called assignment operator" << std::endl;
	if (rhs.getSignGrade() < 1 || rhs.getExecGrade() < 1)
		throw Form::GradeTooHighException();
	if (rhs.getSignGrade() > 150 || rhs.getExecGrade() > 150)
		throw Form::GradeTooLowException();
	_signed = rhs.isSigned();
	return *this;
}

std::string const	&Form::getName(void) const
{
	return _name;
}

size_t const	&Form::getSignGrade(void) const
{
	return _signGrade;
}

size_t const	&Form::getExecGrade(void) const
{
	return _execGrade;
}

bool const		&Form::isSigned(void) const
{
	return _signed;
}

void			Form::beSigned(Bureaucrat const &signer)
{
	if (signer.getGrade() > _signGrade)
		throw Form::GradeTooLowException();
	_signed = true;
}

void			Form::checkExecute(Bureaucrat const &executor) const
{
	if (!_signed)
		throw Form::UnsignedFormException();
	if (_execGrade < executor.getGrade())
		throw Form::GradeTooLowException();
}

std::ostream	&operator<<(std::ostream &out, Form const &f)
{
	out << f.getName() << ", contract with sign grade " << f.getSignGrade() <<
		" and exec grade " << f.getExecGrade() << ", is signed? " << f.isSigned();
	return out;
}
