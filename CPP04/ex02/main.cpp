/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 11:42:04 by esoulard          #+#    #+#             */
/*   Updated: 2020/12/29 13:34:45 by esoulard         ###   ########.fr       */
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
	vlc->push(bob);
	std::cout << "main aft bob push" << std::endl;
	vlc->push(jim);
	std::cout << "main aft jim push" << std::endl;
	
	for (int i = 0; i < vlc->getCount(); ++i)
	{
		std::cout << "x" << std::endl;
		ISpaceMarine* cur = vlc->getUnit(i);
		std::cout << "y" << std::endl;
		cur->battleCry();
		cur->rangedAttack();
		cur->meleeAttack();
	}
	delete vlc;

	return 0;
}