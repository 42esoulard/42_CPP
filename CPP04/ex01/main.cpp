/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 14:48:16 by esoulard          #+#    #+#             */
/*   Updated: 2021/01/04 19:39:05 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wasteland.h"

int main(void) {

	Character* me = new Character("me");

	std::cout << *me;
	std::cout << std::endl;

	std::cout << "-------------ENEMY INSTANCE - SUBTYPE RS----------------" << std::endl;
	Enemy* b = new RadScorpion();
	std::cout << std::endl;

	std::cout << "--------------AWEAPON INSTANCES - DIFFERENT SUBTYPES---------------" << std::endl;
	AWeapon* pr = new PlasmaRifle();
	std::cout << "-----------------------------" << std::endl;
	AWeapon* pf = new PowerFist();
	std::cout << std::endl;

	std::cout << std::endl;
	std::cout << "-----------------------------" << std::endl;
	std::cout << std::endl;

	std::cout << "-------------EQUIP WEAPON----------------" << std::endl;
	me->equip(pr);
	std::cout << *me;

	std::cout << std::endl;
	std::cout << "--------------CHANGE WEAPON + ATTACK---------------" << std::endl;
	me->equip(pf);
	me->attack(b);
	std::cout << *me << std::endl;

	std::cout << std::endl;
	me->equip(pr);
	std::cout << *me << std::endl;
	me->attack(b);
	std::cout << *me << std::endl;
	me->attack(b);
	std::cout << *me << std::endl;
	me->attack(b);
	std::cout << *me << std::endl;
	//enemy has been killed and deleted in character::attack()
	//we can see his pts don't go below 0
	std::cout << std::endl;
	std::cout << "-----------------------------" << std::endl;
	std::cout << std::endl;


	std::cout << "-------------ENEMY INSTANCE - SUBTYPE SM----------------" << std::endl;
	Enemy* c = new SuperMutant();
	std::cout << std::endl;

	me->equip(pf);
	std::cout << *me << std::endl;
	me->attack(c);
	std::cout << *me << std::endl;

	std::cout << std::endl;
	me->equip(pr);
	std::cout << *me << std::endl;
	me->attack(c);
	std::cout << *me << std::endl;
	me->attack(c);
	std::cout << *me << std::endl;

	me->equip(pf);
	std::cout << *me << std::endl;
	std::cout << "-------------CHARACTER OUT OF AP----------------" << std::endl;
	me->attack(c);

	std::cout << "-------------RECOVERING AP + REACHING MAX----------------" << std::endl;
	me->recoverAP();
	me->recoverAP();
	me->recoverAP();
	me->recoverAP();
	me->recoverAP();
	std::cout << *me << std::endl;

	std::cout << std::endl;
	std::cout << "-----------------------------" << std::endl;
	std::cout << std::endl;

	if (c)
		delete c;
	std::cout << std::endl;
	delete pf;
	std::cout << std::endl;
	delete pr;
	std::cout << std::endl;
	delete me;

	return 0;
}