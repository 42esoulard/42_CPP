/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 12:32:44 by esoulard          #+#    #+#             */
/*   Updated: 2021/01/05 15:16:44 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include <iostream>

Intern::Intern(void) {

	std::cout << "[Intern] Default constructor called" << std::endl;
};

Intern::Intern(Intern const &src) {

	std::cout << "[Intern] Copy constructor called" << std::endl;
	*this = src;
};

Intern::~Intern(void) {

	std::cout << "[Intern] Destructor called" << std::endl;
};

Intern & Intern::operator=(Intern const &rhs) {

	std::cout << "[Intern] Assignation operator called" << std::endl;
	return *this;
};


AForm 	*Intern::shrubberyFactory(std::string const &target) {

	return new ShrubberyCreationForm(target);
};

AForm 	*Intern::robotomyFactory(std::string const &target) {

	return new RobotomyRequestForm(target);
};

AForm 	*Intern::presidentialFactory(std::string const &target) {

	return new PresidentialPardonForm(target);
};


AForm 	*Intern::makeForm(std::string const &formName, std::string const &target) {

	for (int i = 0; i < 3; i++) {

		if (formName.compare(_formNames[i]) == 0) {
			std::cout << "Intern creates " << formName << " form." << std::endl;
			return (this->*_formConstr[i])(target);
		}
	}
	throw Intern::FormUnknownException(formName);
};