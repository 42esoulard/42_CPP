/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 10:53:17 by esoulard          #+#    #+#             */
/*   Updated: 2020/12/28 13:12:04 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sorcerer.hpp"
#include <iostream>


Sorcerer::Sorcerer(std::string const &name, std::string const &title):
_name(name), _title(title) {

	std::cout << "[Sorcerer Constructor] " << _name << ", " << _title << ", is born!" << std::endl;
};

Sorcerer::Sorcerer(void) {

	std::cout << "Sorcerer: Default constructor called" << std::endl;
};

Sorcerer::Sorcerer(Sorcerer const &src) {

	std::cout << "Sorcerer: Copy constructor called" << std::endl;
};

Sorcerer::~Sorcerer(void) {

	std::cout << "[Sorcerer Destructor] " << _name << ", " << _title << ", is dead. Consequences will never be the same!" << std::endl;
};

Sorcerer & 			Sorcerer::operator=(Sorcerer const &rhs) {

	std::cout << "Sorcerer: Assignation operator called" << std::endl;
};

std::string const 	Sorcerer::getName(void) const {
	
	return this->_name;
};

std::string const 	Sorcerer::getTitle(void) const {
	
	return this->_title;
};

void 				Sorcerer::polymorph(Victim const &victim) const {

	victim.getPolymorphed();
}


std::ostream & 		operator<<(std::ostream &o, Sorcerer const &rhs) {

	return o << "I am " << rhs.getName() << ", " << rhs.getTitle() << " and I like ponies!" << std::endl;
};

