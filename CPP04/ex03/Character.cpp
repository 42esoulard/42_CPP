/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 16:33:03 by esoulard          #+#    #+#             */
/*   Updated: 2020/12/30 16:41:01 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include <iostream>

Character::Character(void) {

	std::cout << "[Character] Default constructor called" << std::endl;
};

Character::Character(std::string const &name) : _name(name) {

	std::cout << "[Character] Default constructor called" << std::endl;

	for (int i = 0; i < 4; i++) {
		_inventory[i] = nullptr;
	}
};

Character::Character(Character const &src) {

	std::cout << "[Character] Copy constructor called" << std::endl;
	*this = src;
};

Character::~Character(void) {

	std::cout << "[Character] Destructor called" << std::endl;
};

Character & Character::operator=(Character const &rhs) {

	std::cout << "[Character] Assignation operator called" << std::endl;
	return *this;
};


std::string const & Character::getName(void) const {

	return this->_name;
};

void 				Character::equip(AMateria* m) {

	if (!m)
		return ;
	for (int i = 0; i < 4; i++) {

		if (!inventory[i])
			inventory[i] = m;
	}	
};

void 				Character::unequip(int idx) {

	inventory[idx] = nullptr;
};

void 				Character::use(int idx, ICharacter& target) {

	inventory[idx]->use(target);
};

