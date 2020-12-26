/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 11:37:31 by esoulard          #+#    #+#             */
/*   Updated: 2020/12/10 17:15:58 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieHorde.hpp"

ZombieHorde::ZombieHorde(int n) {

	this->_horde = new Zombie[n];
	this->_count = n;
	srand((unsigned int)time(NULL));
	for (int i = 0; i < n; i++) {

		this->_horde[i].setName(randNames[rand() % 10]);
		this->_horde[i].setType("heapZombie");
	}
};

ZombieHorde::~ZombieHorde(void) {

	delete [] this->_horde;
	std::cout << "ZombieHorde destroyed, " << this->_count <<
		" Zombies are dead. I mean, re-dead." << std::endl;
	
};

void 		ZombieHorde::announce(void) const {

	for (int i = 0; i < this->_count; i++) {
		this->_horde[i].announce();
	}
};


std::string ZombieHorde::randNames[10] = {	"Albator",
											"Zoidberg", 
											"MartyMcFly", 
											"Xena", 
											"Trillian",
											"Prometheus", 
					 						"Dandelion", 
					 						"Buster Keaton", 
					 						"Buzz Lightyear", 
					 						"Kyle"	};