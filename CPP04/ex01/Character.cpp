/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 15:45:10 by esoulard          #+#    #+#             */
/*   Updated: 2021/01/05 20:13:58 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(std::string const & name) :
_name(name), _actionPoints(40), _weapon(NULL) {

	std::cout << "[Character] Constructor called" << std::endl;
};

Character::Character(void) {

	std::cout << "[Character] Default constructor called" << std::endl;
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

std::ostream & operator<<(std::ostream &o, Character const &rhs) {

	if (rhs.getWeapon())
		return o << rhs.getName() << " has " << rhs.getAP() << " AP and wields a " << rhs.getWeapon()->getName() << std::endl;
	return o << rhs.getName() << " has " << rhs.getAP() << " AP and is unarmed" << std::endl;
};

void 		Character::recoverAP(void) {

	int rec = 10;
	if (this->_actionPoints + rec >= 40)
		rec = 40 - this->_actionPoints;
	this->_actionPoints += rec;
	std::cout << _name << " recovered " << rec << "AP! They have " << _actionPoints << "AP!" << std::endl;
};

void 		Character::equip(AWeapon* weapon) {

	this->_weapon = weapon;
};

void 		Character::attack(Enemy* &enemy) {

	if (!enemy)
		std::cout << "Enemy's already dead.. Ô the humanity.." << std::endl;
	else if (_weapon && this->_actionPoints >= _weapon->getAPCost()) {
		this->_actionPoints -= _weapon->getAPCost();
		std::cout << _name << " attacks " << enemy->getType() << " with a " << _weapon->getName() << std::endl; 
		_weapon->attack();
		enemy->takeDamage(_weapon->getDamage());
		if (enemy->getHP() <= 0) {
			delete enemy;
			enemy = nullptr;
		}
	}
	else if (_weapon)
		std::cout << "No AP, no attack!" << std::endl;
};

std::string const 	&Character::getName(void) const {

	return this->_name;
};

int	 	 			Character::getAP(void) const {

	return this->_actionPoints;
};

AWeapon				*Character::getWeapon(void) const {

	if (this->_weapon)
		return this->_weapon;
	return NULL;
};