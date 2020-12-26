/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 13:27:50 by esoulard          #+#    #+#             */
/*   Updated: 2020/12/23 21:17:46 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(void) {

	std::cout << std::endl;
	std::cout << "[CL4P-TP default constructor called]" << std::endl;
};

ClapTrap::ClapTrap(ClapTrap const &src) {

	std::cout << "[CL4P-TP copy constructor called]" << std::endl;
	*this = src;
};

ClapTrap::~ClapTrap(void) {

	std::cout << "[CL4P-TP destructor called]" << std::endl;
	std::cout << std::endl;
};

ClapTrap & ClapTrap::operator=(ClapTrap const &rhs) {

	this->_hitPoints = rhs._hitPoints;
	this->_maxHitPoints = rhs._maxHitPoints;
	this->_energyPoints = rhs._energyPoints;
	this->_maxEnergyPoints = rhs._maxEnergyPoints;
	this->_lvl = rhs._lvl;
	this->_name = rhs._name;
	this->_meleeAttackDamage = rhs._meleeAttackDamage;
	this->_rangedAttackDamage = rhs._rangedAttackDamage;
	this->_armorDamageReduction = rhs._armorDamageReduction;
	std::cout << "[CL4P-TP assignation operator called]" << std::endl;
};

//-------------------------------------------------
//GETTERS
std::string const 	ClapTrap::getName(void) const {

	return this->_name;
};

int const 			ClapTrap::getHP(void) const {

	return this->_hitPoints;
};

int const 			ClapTrap::getEP(void) const {

	return this->_energyPoints;
};
//-------------------------------------------------

//<TAKE DAMAGE>, returns < 1: INSTANCE ALIVE> <0: INSTANCE DEAD>
int ClapTrap::takeDamage(unsigned int amount) {

	if (amount == 0)
		return 1;
	if (amount <= this->_armorDamageReduction)
		amount = 0;
	else
		amount -= this->_armorDamageReduction;
	std::cout << "[" << this->_name << "'s armor saves him " << this->_armorDamageReduction
	<< "HP of damage. " << this->_name << " loses " << amount << "HP!]" << std::endl;
	if (amount == 0) {
		std::cout << "[" << this->_name << "]: Not even a scratch!" << std::endl;
		return 1;
	}
	this->_hitPoints -= amount;
	if (this->_hitPoints > 0)
		std::cout << "[" << this->_name << "]: Aww! Come on!" << std::endl;
	else {
		this->_hitPoints = 0;
		std::cout << "[" << this->_name << "]: Argh arghargh death gurgle gurglegurgle urgh... death." << std::endl;
		return 0;
	}
	return 1;
};

//<BE REPAIRED>, adds amount to INSTANCE HITPOINTS
void ClapTrap::beRepaired(unsigned int amount) {

	std::cerr << std::endl;

	this->_hitPoints += amount;
	if (this->_hitPoints > this->_maxHitPoints)
		this->_hitPoints = this->_maxHitPoints;
	std::cout << "[" << this->_name << " regained " 
	<< amount <<  "HP! " << this->_name << " now has " << this->getHP() 
	<< "/" << this->_maxHitPoints << "HP!]" << std::endl;
	std::cout << "[" << this->_name << "]: Ha ha ha! I LIVE! Hahaha!" << std::endl;
};