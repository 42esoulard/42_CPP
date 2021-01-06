/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWeapon.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 13:50:17 by esoulard          #+#    #+#             */
/*   Updated: 2021/01/05 20:10:56 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AWeapon.hpp"

AWeapon::AWeapon(std::string const & name, int apcost, int damage): _name(name), _apCost(apcost), _damage(damage) {

	std::cout << "[AWeapon] " << name << " created!" << std::endl;
};

AWeapon::AWeapon(void) {

	std::cout << "[AWeapon] Default constructor called" << std::endl;
};

AWeapon::AWeapon(AWeapon const &src) {

	std::cout << "[AWeapon] Copy constructor called" << std::endl;
	*this = src;
};

AWeapon::~AWeapon(void) {

	std::cout << "[AWeapon] Destructor called" << std::endl;
};

AWeapon & AWeapon::operator=(AWeapon const &rhs) {

	std::cout << "[AWeapon] Assignation operator called" << std::endl;
	this->_name = rhs.getName();
	this->_damage = rhs.getDamage();
	this->_apCost = rhs.getAPCost();

	return *this;
};

std::string const 	&AWeapon::getName(void) const {

	return this->_name;
};

int 	 			AWeapon::getAPCost(void) const {

	return this->_apCost;
};

int 	 			AWeapon::getDamage(void) const {

	return this->_damage;
};

std::ostream & operator<<(std::ostream &o, AWeapon const &rhs) {

	return o << rhs.getName() << " stats: APCOST " << rhs.getAPCost() << "AP | DAMAGE " << rhs.getDamage() << std::endl;
};