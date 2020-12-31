/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 16:16:27 by esoulard          #+#    #+#             */
/*   Updated: 2020/12/31 12:11:18 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include <iostream>

Cure::Cure(void) : AMateria("cure"){

	std::cout << "[Cure] Default constructor called" << std::endl;
};

Cure::Cure(Cure const &src) {

	std::cout << "[Cure] Copy constructor called" << std::endl;
	*this = src;
};

Cure::~Cure(void) {

	std::cout << "[Cure] Destructor called" << std::endl;
};

Cure & Cure::operator=(Cure const &rhs) {

	std::cout << "[Cure] Assignation operator called" << std::endl;
	this->_xp = rhs.getXP();
	return *this;
};

AMateria* 	Cure::clone(void) const {

	AMateria *clone = new Cure;

	*clone = *this;
	return clone;
};

void 		Cure::use(ICharacter& target) {

	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
	this->_xp += 10;
};