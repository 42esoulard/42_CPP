/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 10:23:39 by esoulard          #+#    #+#             */
/*   Updated: 2021/01/06 12:30:40 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target) :
Form("SCF", 145, 137, target) {

	std::cout << "[ShrubberyCreationForm] Default constructor called" << std::endl;
};

ShrubberyCreationForm::ShrubberyCreationForm(void) :
Form("SCF", 145, 137, "") {

	std::cout << "[ShrubberyCreationForm] Default constructor called" << std::endl;
};

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src) :
Form(src) {

	std::cout << "[ShrubberyCreationForm] Copy constructor called" << std::endl;
	*this = src;
};

ShrubberyCreationForm::~ShrubberyCreationForm(void) {

	std::cout << "[ShrubberyCreationForm] Destructor called" << std::endl;
};

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs) {

	std::cout << "[ShrubberyCreationForm] Assignation operator called" << std::endl;
	return *this;
};

void 	ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	
	std::ofstream ofs(this->getTarget() + "_shrubbery");
	ofs << std::endl;
	ofs << "               ,@@@@@@@," << std::endl;
	ofs << "       ,,,.   ,@@@@@@/@@,  .oo8888o." << std::endl;
	ofs << "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o" << std::endl;
	ofs << "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'" << std::endl;
	ofs << "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'" << std::endl;
	ofs << "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'" << std::endl;
	ofs << "   `&%\\ ` /%&'    |.|        \\ '|8'" << std::endl;
	ofs << "       |o|        | |         | |" << std::endl;
	ofs << "       |.|        | |         | |" << std::endl;
	ofs << " jgs \\/ ._\\//_/__/  ,\\_//___\\/.  \\_//__/_" << std::endl;
	ofs << std::endl;
	ofs << "           Happy Little Trees" << std::endl;
	ofs.close();
};