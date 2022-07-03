#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

char	*Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return (char *)"[EX][BUREAUCRAT] Given grade was too high";
}

char	*Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return (char *)"[EX][BUREAUCRAT] Given grade was too low";
}

Bureaucrat::Bureaucrat(void) : _name("Roger"), _grade(150)
{
	std::cout << "[BUREAUCRAT] Called default constructor" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat &copy)
{
	std::cout << "[BUREAUCRAT] Called copy constructor" << std::endl;
	*this = copy;
}

Bureaucrat::Bureaucrat(std::string const &name, size_t const &grade) : _name(name)
{
	std::cout << "[BUREAUCRAT] Called custom constructor" << std::endl;
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	_grade = grade;
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "[BUREAUCRAT] Called destructor" << std::endl;
}

Bureaucrat	&Bureaucrat::operator=(Bureaucrat &rhs)
{
	std::cout << "[BUREAUCRAT] Called assignment operator" << std::endl;
	if (rhs.getGrade() < 1)
		throw Bureaucrat::GradeTooHighException();
	if (rhs.getGrade() > 150)
		throw Bureaucrat::GradeTooLowException();
	_grade = rhs.getGrade();
	return *this;
}

std::string const	&Bureaucrat::getName(void) const
{
	return _name;
}

size_t const	&Bureaucrat::getGrade(void) const
{
	return _grade;
}

void			Bureaucrat::increaseGrade(void)
{
	if (_grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	_grade--;
}

void			Bureaucrat::decreaseGrade(void)
{
	if (_grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	_grade++;
}

std::ostream	&operator<<(std::ostream &out, Bureaucrat const &b)
{
	out << b.getName() << ", bureaucrat grade " << b.getGrade();
	return out;
}
