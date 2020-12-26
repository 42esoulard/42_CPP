/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 16:39:01 by esoulard          #+#    #+#             */
/*   Updated: 2020/12/23 21:04:02 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NinjaTrap.hpp"
#include <iostream>
#include <algorithm>

NinjaTrap::NinjaTrap(void) {

	std::cout << "[NINJ4-TP default constructor called]" << std::endl;
};

NinjaTrap::NinjaTrap(std::string const name) {

	this->_name = name;
	this->_maxHitPoints = 60; 
	this->_maxEnergyPoints = 120; 
	this->_meleeAttackDamage = 60; 
	this->_rangedAttackDamage = 5; 
	this->_armorDamageReduction = 0; 
	this->_hitPoints = this->_maxHitPoints;
	this->_energyPoints = this->_maxEnergyPoints;
	this->_lvl = 1;
	std::cout << "[NINJ4-TP " << this->_name << " created]: Let's get this party started!" << std::endl;
};

NinjaTrap::NinjaTrap(NinjaTrap const &src) {

	std::cout << "[NINJ4-TP copy constructor called]" << std::endl;
	*this = src;
};

NinjaTrap::~NinjaTrap(void) {

	std::cout << "[NINJ4-TP " << this->_name << " destroyed]" << std::endl;
};

NinjaTrap & NinjaTrap::operator=(NinjaTrap const &rhs) {

	std::cout << "Assignation operator called" << std::endl;
	this->_maxHitPoints = 60; 
	this->_maxEnergyPoints = 120; 
	this->_meleeAttackDamage = 60; 
	this->_rangedAttackDamage = 5; 
	this->_armorDamageReduction = 0; 
	this->_name = rhs.getName();
	this->_hitPoints = rhs.getHP();
	this->_energyPoints = rhs.getEP();
	this->_lvl = rhs._lvl;

	return *this;
};

//PRINT STATS
std::ostream & operator<<(std::ostream &o, NinjaTrap const &rhs) {

	o << "[NINJ4-TP " << rhs.getName() << " | HP: " << rhs.getHP() 
	<< "/60 | EP: " << rhs.getEP() << "/120]" << std::endl;
};

//<RANGED ATTACK>, returns <DAMAGES CAUSED>
int NinjaTrap::rangedAttack(std::string const & target) const {

	std::cout << std::endl;
	std::cout << "[NINJ4-TP " << this->_name << " attacks " << target << " at range, causing "
	<< this->_rangedAttackDamage << " points of damage!]" << std::endl;

	std::cout << "[" << this->_name << "]: You're listening to 'Short-Range Damage Radio'." << std::endl;

	return this->_rangedAttackDamage;
};

//<MELEEATTACK>, returns <DAMAGES CAUSED>
int NinjaTrap::meleeAttack(std::string const & target) const {

	std::cout << std::endl;
	std::cout << "[NINJ4-TP " << this->_name << " attacks " << target << " with a melee attack, causing "
	<< this->_meleeAttackDamage << " points of damage!]" << std::endl;
	std::cout << "[" << this->_name << "]: Heyyah!" << std::endl;

	return this->_meleeAttackDamage;
};

//--------------------------------------------
//NINJA SHOEBOX
int 	NinjaTrap::ninjaShoebox(FragTrap const &fTrap) const {
	
	int 	damage = 50;

	std::cout << std::endl;
	std::cout << "[NINJ4-TP " << this->_name << " throws a stick at " 
	<< fTrap.getName() << ".. Not really a ninja move but it sure as heck was efficient, causing "
	<< damage << " points of damage!]" << std::endl;
	std::cout << "[" << this->_name << "]: Woooosh!" << std::endl;

	return damage;
};

int 	NinjaTrap::ninjaShoebox(ScavTrap const &sTrap) const {
	
	int 	damage = 30;

	std::cout << std::endl;
	std::cout << "[NINJ4-TP " << this->_name << " stares intensely at SC4V-TP " 
	<< sTrap.getName() << ".. Damn that's intimidating. It causes "
	<< damage << " points of damage!]" << std::endl;
	std::cout << "[" << this->_name << "]: Sssssss!" << std::endl;

	return damage;
};

int 	NinjaTrap::ninjaShoebox(NinjaTrap const &nTrap) const {
	
	int 	damage = 20;

	std::cout << std::endl;
	std::cout << "[NINJ4-TP " << this->_name << " sneaks behind NINJ4-TP " 
	<< nTrap.getName() << " and ties their shoelaces together, causing "
	<< damage << " points of damage!]" << std::endl;
	std::cout << "[" << this->_name << "]: Sneaksneak!" << std::endl;

	return damage;
};

//--------------------------------------------
