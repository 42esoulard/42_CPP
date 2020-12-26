/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 20:15:57 by esoulard          #+#    #+#             */
/*   Updated: 2020/12/23 21:04:27 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SuperTrap.hpp"
#include <iostream>

SuperTrap::SuperTrap(void) {

	std::cout << "[SUP3R-TP default constructor called]" << std::endl;
};

SuperTrap::SuperTrap(std::string const name) : FragTrap(), NinjaTrap() {

	this->_name = name;

	std::cerr << "[SUP3R-TP " << this->_name << " created]: Let's get this party started!" << std::endl;
	
	std::cout << "-----------------------------------------" << std::endl;
	std::cout << "[SUP3R-TP " << this->_name << "STATS: " << std::endl;
	std::cout << "HP = " << this->_hitPoints << "/" << _maxHitPoints << std::endl; 
	std::cout << "EP = " << _energyPoints << "/" << _maxEnergyPoints << std::endl; 
	std::cout << "ARMOR = " << _armorDamageReduction << std::endl;
	std::cout << "MELEE ATTACK DAMAGE = " << _meleeAttackDamage << std::endl;
	std::cout << "RANGED ATTACK DAMAGE = " << _rangedAttackDamage << std::endl;
	std::cout << "-----------------------------------------" << std::endl;

};

SuperTrap::SuperTrap(SuperTrap const &src) {

	std::cout << "[SUP3R-TP copy constructor called]" << std::endl;
};

SuperTrap::~SuperTrap(void) {

	std::cout << "[SUP3R-TP " << this->_name << " destroyed]" << std::endl;
};

SuperTrap & SuperTrap::operator=(SuperTrap const &rhs) {

	std::cout << "[SUP3R-TP assignation operator called]" << std::endl;
};

std::ostream & operator<<(std::ostream &o, SuperTrap const &rhs) {

	o << "[SUP3R-TP " << rhs.getName() << " | HP: " << rhs.getHP()
	<< "/100 | EP: " << rhs.getEP() << "/120]" << std::endl;
};
