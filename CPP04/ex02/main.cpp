/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 11:42:04 by esoulard          #+#    #+#             */
/*   Updated: 2020/12/29 14:58:21 by esoulard         ###   ########.fr       */
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
	
	for (int i = 0; i < vlc->getCount(); ++i)
	{
		ISpaceMarine* cur = vlc->getUnit(i);
		std::cout << std::endl;
		cur->battleCry();
		cur->rangedAttack();
		cur->meleeAttack();
		std::cout << std::endl;
	}

	ISquad* beepboop = new Squad;


	delete vlc;
	delete beepboop;

	return 0;
}