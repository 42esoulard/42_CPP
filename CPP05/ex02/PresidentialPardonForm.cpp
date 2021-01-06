/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 12:21:32 by esoulard          #+#    #+#             */
/*   Updated: 2021/01/06 12:10:10 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(std::string const &target) :
Form("PPF", 25, 5, target) {

	std::cout << "[PresidentialPardonForm] Default constructor called" << std::endl;
};

PresidentialPardonForm::PresidentialPardonForm(void) :
Form("PPF", 25, 5, "") {

	std::cout << "[PresidentialPardonForm] Default constructor called" << std::endl;
};

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &src) :
Form(src) {

	std::cout << "[PresidentialPardonForm] Copy constructor called" << std::endl;
	*this = src;
};

PresidentialPardonForm::~PresidentialPardonForm(void) {

	std::cout << "[PresidentialPardonForm] Destructor called" << std::endl;
};

PresidentialPardonForm & PresidentialPardonForm::operator=(PresidentialPardonForm const &rhs) {

	std::cout << "[PresidentialPardonForm] Assignation operator called" << std::endl;
	return *this;
};

void 	PresidentialPardonForm::execute(Bureaucrat const & executor) const {
	
	std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
};