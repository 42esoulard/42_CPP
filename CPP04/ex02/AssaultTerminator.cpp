/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AssaultTerminator.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 11:35:56 by esoulard          #+#    #+#             */
/*   Updated: 2020/12/29 11:52:50 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AssaultTerminator.hpp"
#include <iostream>

AssaultTerminator::AssaultTerminator(void) {

	std::cout << "[AssaultTerminator] * teleports from space *" << std::endl;
};

AssaultTerminator::AssaultTerminator(AssaultTerminator const &src) {

	std::cout << "[AssaultTerminator] Copy constructor called" << std::endl;
	*this = src;
};

AssaultTerminator::~AssaultTerminator(void) {

	std::cout << "[AssaultTerminator] I’ll be back..." << std::endl;
};

AssaultTerminator & AssaultTerminator::operator=(AssaultTerminator const &rhs) {

	std::cout << "[AssaultTerminator] Assignation operator called" << std::endl;
	return *this;
};

// std::ostream & operator<<(std::ostream &o, AssaultTerminator const &rhs) {

// 	//return o << << std::endl;
// };

ISpaceMarine* 	AssaultTerminator::clone(void) const {

	ISpaceMarine* copy = new AssaultTerminator(*this);

	return (copy);
};

void 			AssaultTerminator::battleCry(void) const {

	std::cout << "This code is unclean. PURIFY IT!" << std::endl;
};

void 			AssaultTerminator::rangedAttack(void) const {

	std::cout << "* does nothing *" << std::endl;
};

void 			AssaultTerminator::meleeAttack(void) const {

	std::cout << "* attacks with chainfists *" << std::endl;
};
