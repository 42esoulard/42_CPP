/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 16:00:09 by esoulard          #+#    #+#             */
/*   Updated: 2020/12/30 16:19:04 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include <iostream>

Ice::Ice(void) : AMateria("ice"){

	std::cout << "[Ice] Default constructor called" << std::endl;
};

Ice::Ice(Ice const &src) {

	std::cout << "[Ice] Copy constructor called" << std::endl;
	*this = src;
};

Ice::~Ice(void) {

	std::cout << "[Ice] Destructor called" << std::endl;
};

Ice & Ice::operator=(Ice const &rhs) {

	std::cout << "[Ice] Assignation operator called" << std::endl;
	this->_xp = rhs.getXP();
	return *this;
};

// std::ostream & operator<<(std::ostream &o, Ice const &rhs) {

// 	return o << "* shoots an ice bolt at NAME *" << std::endl;
// };

AMateria* 	Ice::clone(void) const {

	AMateria *clone = new Ice;

	clone = *this;
	return clone;
};

void 		Ice::use(ICharacter& target) {

	std::cout << "* shoots an ice bolt at " << target.getName() <<" *" << std::endl;
	this->_xp += 10;
};