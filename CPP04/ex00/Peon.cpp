/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Peon.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 11:45:59 by esoulard          #+#    #+#             */
/*   Updated: 2020/12/28 13:12:53 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Peon.hpp"
#include <iostream>

Peon::Peon(std::string const &name) : Victim(name) {
	
	std::cout << "[Peon Constructor] Zog zog." << std::endl;
};

Peon::Peon(void) {

	std::cout << "Peon: Default constructor called" << std::endl;
};

Peon::Peon(Peon const &src) {

	std::cout << "Peon: Copy constructor called" << std::endl;
};

Peon::~Peon(void) {

	std::cout << "[Peon Destructor] Bleuark..." << std::endl;
};

void 			Peon::getPolymorphed(void) const {

 	std::cout << "[Peon morph]" << _name << " has been turned into a pink pony!" << std::endl;
};

Peon & 			Peon::operator=(Peon const &rhs) {

	std::cout << "Peon: Assignation operator called" << std::endl;
};

