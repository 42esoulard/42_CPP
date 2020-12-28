/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PlasmaRifle.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 14:20:11 by esoulard          #+#    #+#             */
/*   Updated: 2020/12/28 19:05:06 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PlasmaRifle.hpp"

PlasmaRifle::PlasmaRifle(void) : AWeapon("Plasma Rifle", 5, 21) {

	std::cout << "[PlasmaRifle] Default constructor called" << std::endl;
};

PlasmaRifle::PlasmaRifle(PlasmaRifle const &src) {

	std::cout << "[PlasmaRifle] Copy constructor called" << std::endl;
	*this = src;
};

PlasmaRifle::~PlasmaRifle(void) {

	std::cout << "[PlasmaRifle] Destructor called" << std::endl;
};

PlasmaRifle & 	PlasmaRifle::operator=(PlasmaRifle const &rhs) {

	std::cout << "[PlasmaRifle] Assignation operator called" << std::endl;
	return *this;
};

void 			PlasmaRifle::attack(void) const {
	
	std::cout << "* piouuu piouuu piouuu *" << std::endl;
};
