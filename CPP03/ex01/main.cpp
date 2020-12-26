/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 16:39:37 by esoulard          #+#    #+#             */
/*   Updated: 2020/12/22 13:13:15 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main(void) {

	FragTrap CB12A6("CB12A6");
	ScavTrap AJX5("AJX5");
	int			fight = 1;
	int			round = 0;

	srand((unsigned int)time(NULL));
	while (fight && round < 3) {

		std::cout << "------ ROUND " << round + 1 << "------" << std::endl;
		if (!(fight = AJX5.takeDamage(CB12A6.rangedAttack(AJX5.getName()))))
			break;
		if (!(fight = CB12A6.takeDamage(AJX5.meleeAttack(CB12A6.getName()))))
			break;
		if (!(fight = AJX5.takeDamage(CB12A6.vaulthunter_dot_exe(AJX5.getName()))))
			break;
		if (!(fight = CB12A6.takeDamage(AJX5.challengeNewcomer(CB12A6.getName()))))
			break;

		if (rand() % 100 > 50)
			CB12A6.beRepaired(rand() % 100);
		if (rand() % 100 > 50)
			AJX5.beRepaired(rand() % 100);

		std::cout << "--------------------" << std::endl;
		std::cout << AJX5;
		std::cout << CB12A6;
		std::cout << "--------------------" << std::endl;

		round++;
	}

	std::cout << std::endl;

	if (!fight) {
		std::cout << "--------------------" << std::endl;
		std::cout << AJX5;
		std::cout << CB12A6;
		std::cout << "--------------------" << std::endl;
		std::cout << std::endl;
		if (AJX5.getHP() == 0)
			std::cout << "------| AJX5 IS DEAD! |------" << std::endl;
		if (CB12A6.getHP() == 0)
			std::cout << "------| CB12A6 IS DEAD! |------" << std::endl;
	}
	else
		std::cout << "------| IT'S A DRAW! |------" << std::endl;
	std::cout << std::endl;

	return 0;
	//takeDamage : check return, if 1: FragTrap dead, break loop
	//*attack: send return (hitpoints) to target takeDamage
	//[std::cout << FragTrapInstance] gives stats of the instance (hp/ep)
}