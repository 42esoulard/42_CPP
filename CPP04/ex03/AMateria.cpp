/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 15:53:46 by esoulard          #+#    #+#             */
/*   Updated: 2020/12/31 12:10:23 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include <iostream>


AMateria::AMateria(void) {

	std::cout << "[AMateria] Default constructor called" << std::endl;
};

AMateria::AMateria(std::string const & type) :
_type(type), _xp(0) {

	std::cout << "[AMateria] Constructor called" << std::endl;
};

AMateria::AMateria(AMateria const &src) {

	std::cout << "[AMateria] Copy constructor called" << std::endl;
	*this = src;
};

AMateria::~AMateria(void) {

	std::cout << "[AMateria] Destructor called" << std::endl;
};

AMateria & AMateria::operator=(AMateria const &rhs) {

	std::cout << "[AMateria] Assignation operator called" << std::endl;
	this->_xp = rhs.getXP();
	this->_type = rhs.getType();
	return *this;
};

std::string const & AMateria::getType(void) const {

	return this->_type;
};

unsigned int 		AMateria::getXP(void) const {

	return this->_xp;
};

void 		AMateria::use(ICharacter& target) {

};


		