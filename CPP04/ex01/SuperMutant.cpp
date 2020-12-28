/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperMutant.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 15:35:17 by esoulard          #+#    #+#             */
/*   Updated: 2020/12/28 19:04:35 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SuperMutant.hpp"

SuperMutant::SuperMutant(void) :
Enemy(170, "Super Mutant") {

	std::cout << "[SuperMutant] Gaaah. Me want smash heads!" << std::endl;
};

SuperMutant::SuperMutant(SuperMutant const &src) {

	std::cout << "[SuperMutant] Copy constructor called" << std::endl;
	*this = src;
};

SuperMutant::~SuperMutant(void) {

	std::cout << "[SuperMutant] Aaargh..." << std::endl;
};

SuperMutant & SuperMutant::operator=(SuperMutant const &rhs) {

	std::cout << "[SuperMutant] Assignation operator called" << std::endl;
	return *this;
};

void 		SuperMutant::takeDamage(int damage) {

 	damage -= 3;
	if (damage > 0)
		this->_hitPoints -= damage;
	std::cout << "SuperMutant lost " << damage << "! Enemy now has " << this->_hitPoints << "left!" << std::endl;
};

