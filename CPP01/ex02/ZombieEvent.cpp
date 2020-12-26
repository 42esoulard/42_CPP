/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 13:15:43 by esoulard          #+#    #+#             */
/*   Updated: 2020/12/10 17:12:50 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieEvent.hpp"
#include <ctime>

ZombieEvent::ZombieEvent(void) {

};

ZombieEvent::~ZombieEvent(void) {

};



void 		ZombieEvent::setZombieType(Zombie *newZombie, std::string type) {

	newZombie->setType(type);
};

Zombie 		*ZombieEvent::newZombie (std::string name) {

	Zombie *heapZombie = new Zombie();
	heapZombie->setName(name);
	ZombieEvent::setZombieType(heapZombie, "heapZombie");
	return heapZombie;
};

void 		ZombieEvent::randomChump (void) {

	srand((unsigned int)time(NULL));
	Zombie stackZombie = Zombie();
	stackZombie.setName(randNames[rand() % 10]);
	ZombieEvent::setZombieType(&stackZombie, "stackZombie");
	stackZombie.announce();
	return ;
};


std::string ZombieEvent::randNames[10] = {	"Albator",
											"Zoidberg", 
											"MartyMcFly", 
											"Xena", 
											"Trillian",
											"Prometheus", 
					 						"Dandelion", 
					 						"Buster Keaton", 
					 						"Buzz Lightyear", 
					 						"Kyle"	};
