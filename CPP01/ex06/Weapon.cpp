/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 19:34:20 by esoulard          #+#    #+#             */
/*   Updated: 2020/12/11 15:36:09 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type): _type(type) {
	
};

Weapon::~Weapon(void){
	
};

const std::string 	&Weapon::getType(void) const {
	
	return this->_type;
};

void 				Weapon::setType(std::string type) {
	
	this->_type = type;
};
