/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 11:42:04 by esoulard          #+#    #+#             */
/*   Updated: 2020/12/30 14:05:16 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ISquad.hpp"
#include "Squad.hpp"
#include "ISpaceMarine.hpp"
#include "TacticalMarine.hpp"
#include "AssaultTerminator.hpp"
#include <iostream>

int main(void) {


	std::cout << "-----------INIT-----------" << std::endl;

	ISpaceMarine* bob = new TacticalMarine;
	ISpaceMarine* jim = new AssaultTerminator;
	
	ISquad* vlc = new Squad;
	std::cout << std::endl;

	vlc->push(bob);

	vlc->push(jim);
	vlc->push(jim);
	//check that same instance isnt added twice

	std::cout << std::endl;
	std::cout << "---------FIRST CHECKS-------------" << std::endl;

	for (int i = 0; i < vlc->getCount(); ++i)
	{
		ISpaceMarine* cur = vlc->getUnit(i);
		//check that squad contains what it should
		//and getUnit returns the right instance
		std::cout << std::endl;
		cur->battleCry();
		cur->rangedAttack();
		cur->meleeAttack();
		//check that subtype functions are called
		std::cout << std::endl;
	}

	std::cout << "---------EMPTY-------------" << std::endl;

	Squad* emptySquad = new Squad;
	//check that empty squad doesn't segv
	for (int i = 0; i < emptySquad->getCount(); ++i)
	{
		//nothing should happen here because count 0
		ISpaceMarine* cur = emptySquad->getUnit(i);
		std::cout << std::endl;
		cur->battleCry();
		cur->rangedAttack();
		cur->meleeAttack();
		std::cout << std::endl;
	}

	std::cout << std::endl;
	std::cout << "----------DAVE AS A [TM]-----------" << std::endl;

	ISpaceMarine* confusedDave = new TacticalMarine;
	emptySquad->push(confusedDave);
	//ISpaceMarine instance can be assigned either subtype
	//first, dave is a TacticalMarine

	for (int i = 0; i < emptySquad->getCount(); ++i)
	{
		ISpaceMarine* cur = emptySquad->getUnit(0);
		std::cout << std::endl;
		cur->battleCry();
		cur->rangedAttack();
		cur->meleeAttack();
		//TM functions are called
		std::cout << std::endl;	
	}

	std::cout << "---------SQUAD COPY CONSTRUCTION------------" << std::endl;

	Squad* bop = new Squad;

	ISpaceMarine* beep = new TacticalMarine;
	bop->push(beep);

	Squad* tmp = new Squad(*bop);
	//copy constructor

	std::cout << std::endl;
	std::cout << "-----------SQUAD OPERATOR=----------" << std::endl;	

	ISpaceMarine* assertiveBrenda = new AssaultTerminator;
	tmp->push(assertiveBrenda);
	
	*emptySquad = *tmp;
	//assignation, deletes all previously contained marines
	//so.. dave from emptySquad died. So long, dave!
	//he's replaced by clones of beep and brenda.
	
	std::cout << std::endl;
	std::cout << "-------RESULT OF PREVIOUS COPIES (FT DAVE NOW AS AN [AT] in #3)---------" << std::endl;

	confusedDave = new AssaultTerminator;
	//like the phoenix, dave rises from his ashes
	// as an AssaultTerminator

	emptySquad->push(confusedDave);
	//empty squad now contains:
	// #1 clone of beep [TM]
	// #2 clone of assertiveBrenda [AT]
	// #3 confusedDave [AT]
	for (int i = 0; i < emptySquad->getCount(); ++i)
	{
		ISpaceMarine* cur = emptySquad->getUnit(i);
		std::cout << std::endl;
		cur->battleCry();
		cur->rangedAttack();
		cur->meleeAttack();

		std::cout << std::endl;	
	}

	std::cout << "------------------------------" << std::endl;

//deleting squads deletes its spaceMarines

	//vlc will delete bob[TM] and jim[AT]
	delete vlc;
	std::cout << std::endl;

	//bop contains : 
	// #1 beep [TM]
	// bop will delete beep
	delete bop;	
	std::cout << std::endl;

	//tmp contains : 
	// #1 clone of beep[TM]
	// #2 brenda[AT]
	delete tmp;
	std::cout << std::endl;

	//emptysquad contains : 
	// #1 clone of clone of beep[TM]
	// #2 clone of brenda[AT]
	// #3 dave[AT] 
	delete emptySquad;
	
	return 0;
}