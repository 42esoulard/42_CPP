/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 11:42:04 by esoulard          #+#    #+#             */
/*   Updated: 2020/12/30 13:41:42 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ISquad.hpp"
#include "Squad.hpp"
#include "ISpaceMarine.hpp"
#include "TacticalMarine.hpp"
#include "AssaultTerminator.hpp"
#include <iostream>

int main(void) {

	ISpaceMarine* bob = new TacticalMarine;
	ISpaceMarine* jim = new AssaultTerminator;
	
	ISquad* vlc = new Squad;
	std::cout << std::endl;

	vlc->push(bob);

	vlc->push(jim);
	vlc->push(jim);
	//check that same instance isnt added twice

	std::cout << "------------------------------" << std::endl;

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

	std::cout << "------------------------------" << std::endl;

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

	std::cout << "------------------------------" << std::endl;

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

	Squad* bop = new Squad;

	ISpaceMarine* beep = new TacticalMarine;
	bop->push(beep);


	Squad* tmp = new Squad(*bop);
	//copy constructor
	ISpaceMarine* assertiveBrenda = new AssaultTerminator;
	tmp->push(assertiveBrenda);
	
	*emptySquad = *tmp;
	//assignation, deletes all previouslycontained marines
	//so dave died. So long, dave!

	confusedDave = new AssaultTerminator;
	//like the phoenix, dave rises from his ashes
	// as an AssaultTerminator
	
	emptySquad->push(confusedDave);
	//empty squad now contains:
	// #1 beep [TM]
	// #2 assertiveBrenda [AT]
	// #3 confusedDave [AT]
	for (int i = 0; i < emptySquad->getCount(); ++i)
	{
		ISpaceMarine* cur = emptySquad->getUnit(0);
		std::cout << std::endl;
		cur->battleCry();
		cur->rangedAttack();
		cur->meleeAttack();

		std::cout << std::endl;	
	}

	std::cout << "------------------------------" << std::endl;

//deleting squads deletes its spaceMarines

	//vlc will delete jim[AT] and bob[TM]
	delete vlc;
	std::cout << std::endl;

// copy deleting is managed with a boolean check
// to avoid double free. Only original squad members
// are deleted

	//tmp contains : 
	// #1 copy of beep[TM]
	// #2 brenda[AT]
	// tmp will delete brenda
	delete tmp;
	std::cout << std::endl;
	//bop contains : 
	// #1 beep [TM]
	// bop will delete beep
	delete bop;	
	std::cout << std::endl;
	//emptysquad contains : 
	// #1 copy of copy of beep[TM]
	// #2 copy of brenda[AT]
	// #3 dave[AT] 
	//emptySquad will delete dave
	delete emptySquad;
	
	return 0;
}