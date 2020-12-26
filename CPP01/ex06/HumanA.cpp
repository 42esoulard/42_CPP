/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 19:43:37 by esoulard          #+#    #+#             */
/*   Updated: 2020/12/11 15:35:29 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weaponAddr): _name(name), _weaponRef(weaponAddr) {
	
	std::cout << "HumanA created!" << std::endl;
};

HumanA::~HumanA(void) {
	
	std::cout << "HumanA destroyed!" << std::endl;
};

void HumanA::attack(void) const {
	
	std::cout << this->_name << " attacks with " << this->_weaponRef.getType() << std::endl;
};