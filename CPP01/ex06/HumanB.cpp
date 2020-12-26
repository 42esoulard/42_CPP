/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 19:53:19 by esoulard          #+#    #+#             */
/*   Updated: 2020/12/11 15:35:37 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name): _name(name) {
	
	std::cout << "HumanB created!" << std::endl;
};

HumanB::~HumanB(void) {
	
	std::cout << "HumanB destroyed!" << std::endl;
};

void HumanB::setWeapon(Weapon &weaponAddr) {
	
	this->_weaponPtr = &weaponAddr;
};

void HumanB::attack(void) const {
	
	std::cout << this->_name << " attacks with " << this->_weaponPtr->getType() << std::endl;
};