/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 16:33:03 by esoulard          #+#    #+#             */
/*   Updated: 2020/12/31 12:11:28 by esoulard         ###   ########.fr       */
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

	for (int i = 0; i < 4; i++) {
		if (_inventory[i])
			delete _inventory[i];
		_inventory[i] = nullptr;
	}

	std::cout << "[Character] Destructor called" << std::endl;
};

Character & Character::operator=(Character const &rhs) {

	std::cout << "[Character] Assignation operator called" << std::endl;
	
	for (int i = 0; i < 4; i++) {

		delete _inventory[i];
		_inventory[i] = nullptr;
	}

	for (int i = 0; i < 4; i++) {

		_inventory[i] = rhs._inventory[i]->clone();
	}
	_name = rhs.getName();

	return *this;
};


std::string const & Character::getName(void) const {

	return this->_name;
};

void 				Character::equip(AMateria* m) {

	if (!m)
		return ;
	for (int i = 0; i < 4; i++) {

		if (_inventory[i] && _inventory[i] == m) {

			std::cout << _name << " already has <" << m->getType() <<
			" materia> in inventory slot " << i << "!" << std::endl;
			return ;
		}	
	}
	for (int i = 0; i < 4; i++) {

		if (!_inventory[i]) {

			_inventory[i] = m;
			std::cout << _name << " equiped <" << m->getType() <<
			" materia> in inventory slot " << i << "!" << std::endl;
			return ;
		}	
	}
	std::cout << "Character inventory full!" << std::endl;
	delete m;
}

void 				Character::unequip(int idx) {

	if (_inventory[idx]) {
		std::cout << _name << " has unequiped the <" << _inventory[idx]->getType() <<
		" materia> in inventory slot " << idx << "." << std::endl;
	}
	else
		std::cout << _name << " has nothing in inventory slot " << idx <<"." << std::endl;
	_inventory[idx] = nullptr;
};

void 				Character::use(int idx, ICharacter& target) {

	if (_inventory[idx]) {
		_inventory[idx]->use(target);
		std::cout << "[Materia " << _inventory[idx]->getType() << 
		" | " << _inventory[idx]->getXP() << "XP]" << std::endl;
	}
};

