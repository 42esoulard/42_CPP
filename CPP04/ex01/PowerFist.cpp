/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PowerFist.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 14:21:15 by esoulard          #+#    #+#             */
/*   Updated: 2020/12/28 19:04:57 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PowerFist.hpp"

PowerFist::PowerFist(void) :
AWeapon("Power Fist", 8, 50) {

	std::cout << "[PowerFist] Default constructor called" << std::endl;
};

PowerFist::PowerFist(PowerFist const &src) {

	std::cout << "[PowerFist] Copy constructor called" << std::endl;
	*this = src;
};

PowerFist::~PowerFist(void) {

	std::cout << "[PowerFist] Destructor called" << std::endl;
};

PowerFist & PowerFist::operator=(PowerFist const &rhs) {

	std::cout << "[PowerFist] Assignation operator called" << std::endl;
	return *this;  
};

void 		PowerFist::attack(void) const {
	
	std::cout << "* pschhh... SBAM! *" << std::endl;
};

