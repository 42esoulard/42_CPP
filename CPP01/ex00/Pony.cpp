/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 12:03:44 by esoulard          #+#    #+#             */
/*   Updated: 2020/12/07 12:50:15 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"

Pony::Pony(std::string name, std::string color, std::string mood): _name(name), 
	_color(color), _mood(mood) {

	std::cout << "[CREATOR:] Pony " << this->_name << " has been spawned!" << std::endl;
};

Pony::~Pony(void) {

	std::cout << "[DESTRUCTOR:] Pony " << this->_name << " has been sent back to the pony farm. Bye bye, pony!"
	<< std::endl;
};


void Pony::runLikeTheWind(void) const {

	std::cout << this->_name << " is running like the wind! Look at that " << this->_color <<
	" lightning bolt!!" << std::endl;
};

void Pony::bakeCupcakes(void) const {

	std::cout << this->_name << " is feeling " << this->_mood <<
	"... They just started baking cupcakes." << std::endl;
};

void Pony::breatheFire(void) const {

	std::cout << this->_name << " seems to be.. breathing fire? Is that even a pony thing?" << std::endl;
};