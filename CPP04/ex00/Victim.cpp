/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 10:53:41 by esoulard          #+#    #+#             */
/*   Updated: 2021/01/05 20:01:49 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Victim.hpp"
#include <iostream>

Victim::Victim(std::string const &name) : _name(name) {

	std::cout << "[Victim Constructor] Some random victim called " << _name << " just appeared!" << std::endl;
};

Victim::Victim(void) {

	std::cout << "Victim: Default constructor called" << std::endl;
};

Victim::Victim(Victim const &src) {

	std::cout << "Victim: Copy constructor called" << std::endl;
	*this = src;
};

Victim::~Victim(void) {

	std::cout << "[Victim Destructor] Victim " << _name << " just died for no apparent reason!" << std::endl;
};

Victim & 			Victim::operator=(Victim const &rhs) {

	std::cout << "Victim: Assignation operator called" << std::endl;
	this->_name = rhs.getName();
	return *this;
};

std::string const 	&Victim::getName(void) const {
	
	return this->_name;
};

void 				Victim::getPolymorphed(void) const {

	std::cout << "[Victim morph] " << _name << " has been turned into a cute little sheep!" << std::endl;
};

std::ostream & 		operator<<(std::ostream &o, Victim const &rhs) {

	return o << "I'm " << rhs.getName() << " and I like otters!" << std::endl;
};

