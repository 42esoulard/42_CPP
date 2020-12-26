/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 16:39:01 by esoulard          #+#    #+#             */
/*   Updated: 2020/12/23 21:03:08 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap(void): _name("Nobody"), _maxHitPoints(100),
	_maxEnergyPoints(100), _meleeAttackDamage(30), _rangedAttackDamage(20),
	_armorDamageReduction(5) {

	std::cout << "[Default constructor called]" << std::endl;
};

FragTrap::FragTrap(std::string const name): _name(name), _maxHitPoints(100),
	_maxEnergyPoints(100), _meleeAttackDamage(30), _rangedAttackDamage(20),
	_armorDamageReduction(5) {

	this->_hitPoints = this->_maxHitPoints;
	this->_energyPoints = this->_maxEnergyPoints;
	this->_lvl = 1;
	std::cout << "[FR4G-TP " << this->_name << " created]: Let's get this party started!" << std::endl;
};

FragTrap::FragTrap(FragTrap const &src): _maxHitPoints(100),
	_maxEnergyPoints(100), _meleeAttackDamage(30), _rangedAttackDamage(20),
	_armorDamageReduction(5) {

	std::cout << "[Copy constructor called]" << std::endl;
	*this = src;
};

FragTrap::~FragTrap(void) {

	std::cout << "[FR4G-TP " << this->_name << " destroyed]" << std::endl;
};

FragTrap & FragTrap::operator=(FragTrap const &rhs) {

	std::cout << "Assignation operator called" << std::endl;
	this->_name = rhs.getName();
	this->_hitPoints = rhs.getHP();
	this->_energyPoints = rhs.getEP();
	this->_lvl = rhs._lvl;

	return *this;
};

//-------------------------------------------------
//GETTERS
std::string const 	FragTrap::getName(void) const {

	return this->_name;
};

int const 			FragTrap::getHP(void) const {

	return this->_hitPoints;
};

int const 			FragTrap::getEP(void) const {

	return this->_energyPoints;
};
//-------------------------------------------------

//PRINT STATS
std::ostream & operator<<(std::ostream &o, FragTrap const &rhs) {

	o << "[FR4G-TP " << rhs.getName() << " | HP: " << rhs.getHP()
	<< "/100 | EP: " << rhs.getEP() << "/100]" << std::endl;
};

//<RANGED ATTACK>, returns <DAMAGES CAUSED>
int FragTrap::rangedAttack(std::string const & target) const {

	std::cout << std::endl;
	std::cout << "[FR4G-TP " << this->_name << " attacks " << target << " at range, causing "
	<< this->_rangedAttackDamage << " points of damage!]" << std::endl;

	std::cout << "[" << this->_name << "]: You're listening to 'Short-Range Damage Radio'." << std::endl;

	return this->_rangedAttackDamage;
};

//<MELEEATTACK>, returns <DAMAGES CAUSED>
int FragTrap::meleeAttack(std::string const & target) const {

	std::cout << std::endl;
	std::cout << "[FR4G-TP " << this->_name << " attacks " << target << " with a melee attack, causing "
	<< this->_meleeAttackDamage << " points of damage!]" << std::endl;
	std::cout << "[" << this->_name << "]: Heyyah!" << std::endl;

	return this->_meleeAttackDamage;
};

//<TAKE DAMAGE>, returns < 1: INSTANCE ALIVE> <0: INSTANCE DEAD>
int FragTrap::takeDamage(unsigned int amount) {

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
void FragTrap::beRepaired(unsigned int amount) {

	std::cout << std::endl;

	this->_hitPoints += amount;
	if (this->_hitPoints > this->_maxHitPoints)
		this->_hitPoints = this->_maxHitPoints;
	std::cout << "[FR4G-TP " << this->_name << " regained " 
	<< amount <<  "HP! " << this->_name << " now has " << this->getHP() 
	<< "/100HP!]" << std::endl;
	std::cout << "[" << this->_name << "]: Ha ha ha! I LIVE! Hahaha!" << std::endl;
};

//<RANDOM ATTACK>, -25 EP, returns <DAMAGES CAUSED>
int FragTrap::vaulthunter_dot_exe(std::string const & target) {

	std::cout << std::endl;

	if (this->_energyPoints < 25) {
		std::cout << "[" << this->_name << "]: Crap, no more shots left!" << std::endl;
		return 0;
	}
	this->_energyPoints -= 25;
	
	std::cout << "[FR4G-TP " << this->_name << " GETS READY TO LAUNCH A RANDOM ATTACK ON "
	<< target << "!]" << std::endl; 

	int index = rand() % 5; 

	std::cout << "[FR4G-TP " << this->_name << " launches a " << _exeNames[index] 
	<< " Attack on " << target << "!" << std::endl; 

	int damage = (this->*_exeTab[index])(target);

	std::cout << "[It caused " << damage << " points of damage to " << target << "!]" << std::endl;

   	return damage;
};

//-------------------------------------------------
//<SLEEP ATTACK>, causes 2 damage
int FragTrap::_sleepAttack(std::string const & target) const {
	
	std::cout << "[" << this->_name << "]: Yessss, look into my eyes. You're getting sleepy. You're getting... zzzzzz... Zzzzzz..." << std::endl;
	return 2;
};

//<STAY ATTACK>, causes 30 damage
int FragTrap::_stayAttack(std::string const & target) const {

	std::cout << "[" << this->_name << "]: Success! My spell to make you want to hang out with me worked!" << std::endl;
	return 30;
};

//<FATAL ATTACK>, causes 100 damage
int FragTrap::_fatalAttack(std::string const & target) const {

	std::cout << "[" << this->_name << "]: Is it dead? Can, can I open my eyes now?" << std::endl;
	return 100;
};

//<GRENADE ATTACK>, causes 60 damage
int FragTrap::_grenadeAttack(std::string const & target) const {
	
	std::cout << "[" << this->_name << "]: Bad guy go boom!" << std::endl;
	return 60;
};

//<FREEZE ATTACK>, causes 25 damage
int FragTrap::_freezeAttack(std::string const & target) const {

	std::cout << "[" << this->_name << "]: Cryo me a river!" << std::endl;
	return 25;
};
//-------------------------------------------------
