/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 12:21:32 by esoulard          #+#    #+#             */
/*   Updated: 2021/01/04 12:29:28 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(std::string const &target) :
AForm("PPF", 25, 5, target) {

	std::cout << "[PresidentialPardonForm] Default constructor called" << std::endl;
};

PresidentialPardonForm::PresidentialPardonForm(void) {

	std::cout << "[PresidentialPardonForm] Default constructor called" << std::endl;
};

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &src) {

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
	
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
};