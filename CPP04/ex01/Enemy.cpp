/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 15:12:01 by esoulard          #+#    #+#             */
/*   Updated: 2020/12/28 18:07:36 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.hpp"

Enemy::Enemy(int hp, std::string const &type) :
_hitPoints(hp), _type(type) {

	std::cout << "[Enemy] type " << _type << " | " << _hitPoints << " HP created" << std::endl;
};


Enemy::Enemy(void) {

	std::cout << "[Enemy] Default constructor called" << std::endl;
};

Enemy::Enemy(Enemy const &src) {

	std::cout << "[Enemy] Copy constructor called" << std::endl;
	*this = src;
};

Enemy::~Enemy(void) {

	std::cout << "[Enemy] Destructor called" << std::endl;
};

Enemy & Enemy::operator=(Enemy const &rhs) {

	std::cout << "[Enemy] Assignation operator called" << std::endl;
	return *this;
};
		
std::string 	Enemy::getType(void) const {

	return this->_type;
};

int 			Enemy::getHP(void) const {

	return this->_hitPoints;
};


void 		Enemy::takeDamage(int damage) {

	if (damage > 0) {
		this->_hitPoints -= damage;
		if (this->_hitPoints < 0)
			this->_hitPoints = 0;
		std::cout << "RadScorpion lost " << damage << "! Enemy now has " << this->_hitPoints << "left!" << std::endl;
	}

};

std::ostream & operator<<(std::ostream &o, Enemy const &rhs) {

	return o << rhs.getType() << " | " << rhs.getHP() << "HP" << std::endl;
};
