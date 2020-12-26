/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 13:07:34 by esoulard          #+#    #+#             */
/*   Updated: 2020/12/10 17:16:11 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void) {

	std::cout << "Zombie has been created! :)" << std::endl;
};

Zombie::~Zombie(void) {

	std::cout << "Zombie " << this->_name << " has been destroyed :( " << std::endl;
};

void 	Zombie::announce(void) const {

	std::cout << "<" << this->_name << " (" << this->_type << ")> Braiiiiiiinnnssss..." << std::endl;
};

void 	Zombie::setName(std::string name){
	
	this->_name = name;
};

void 	Zombie::setType(std::string type){
	
	this->_type = type;
};
