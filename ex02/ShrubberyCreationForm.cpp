#include <fstream>
#include <iostream>
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : Form("ShrubberyCreationForm", 145, 137), _target("default target")
{
	std::cout << "[SHRUBBERYCREATIONFORM] Called default private constructor" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &copy) : Form(copy.getName(), copy.getSignGrade(), copy.getExecGrade()), _target(copy.getTarget())
{
	std::cout << "[SHRUBBERYCREATIONFORM] Called copy constructor" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target) : Form("ShrubberyCreationForm", 145, 137), _target(target)
{
	std::cout << "[SHRUBBERYCREATIONFORM] Called constructor" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << "[SHRUBBERYCREATIONFORM] Called destructor" << std::endl;
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(ShrubberyCreationForm &rhs)
{
	std::cout << "[SHRUBBERYCREATIONFORM] Called assign operator, impossible to do anything" << std::endl;
	Form::operator=(rhs);
	return *this;
}

std::string const	&ShrubberyCreationForm::getTarget(void) const
{
	return _target;
}

void				ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	std::ofstream	output;
	
	std::cout << "[SHRUBBERYCREATIONFORM] Called execute" << std::endl;
	checkExecute(executor);
	output.open(_target + "_shrubbery");
	output << "my-app/" << std::endl;
	output << "├─ node_modules/" << std::endl;
	output << "├─ public/" << std::endl;
	output << "│  ├─ favicon.ico" << std::endl;
	output << "│  ├─ index.html" << std::endl;
	output << "│  ├─ robots.txt" << std::endl;
	output << "├─ src/" << std::endl;
	output << "│  ├─ index.css" << std::endl;
	output << "│  ├─ index.js" << std::endl;
	output << "├─ .gitignore" << std::endl;
	output << "├─ package.json" << std::endl;
	output << "├─ README.md" << std::endl;
	output.close();
}
