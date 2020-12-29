/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TacticalMarine.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 11:19:07 by esoulard          #+#    #+#             */
/*   Updated: 2020/12/29 14:55:57 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TacticalMarine.hpp"
#include <iostream>

TacticalMarine::TacticalMarine(void) {

	std::cout << "[TacticalMarine] Tactical Marine ready for battle!" << std::endl;
};

TacticalMarine::TacticalMarine(TacticalMarine const &src) {

	std::cout << "[TacticalMarine] Copy constructor called" << std::endl;
	*this = src;
};

TacticalMarine::~TacticalMarine(void) {

	std::cout << "[TacticalMarine]  Aaargh..." << std::endl;
};

TacticalMarine & TacticalMarine::operator=(TacticalMarine const &rhs) {

	std::cout << "[TacticalMarine] Assignation operator called" << std::endl;
	return *this;
};


ISpaceMarine* 	TacticalMarine::clone(void) const {

	ISpaceMarine* copy = new TacticalMarine(*this);

	return (copy);
};

void 			TacticalMarine::battleCry(void) const {

	std::cout << "For the holy PLOT!" << std::endl;
};

void 			TacticalMarine::rangedAttack(void) const {

	std::cout << "* attacks with a bolter *" << std::endl;
};

void 			TacticalMarine::meleeAttack(void) const {

	std::cout << "* attacks with a chainsword *" << std::endl;
};
