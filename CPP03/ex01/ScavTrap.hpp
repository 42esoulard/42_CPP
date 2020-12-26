/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 16:39:20 by esoulard          #+#    #+#             */
/*   Updated: 2020/12/22 12:55:03 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ScavTrap_HPP
#define ScavTrap_HPP

#include <iostream>

class ScavTrap {
	
	public:
		ScavTrap(std::string const name);
		ScavTrap(ScavTrap const &src);
		~ScavTrap(void);
		ScavTrap & operator=(ScavTrap const &rhs);

		std::string const 	getName(void) const;
		int const 			getHP(void) const;
		int const 			getEP(void) const;

		int 	rangedAttack(std::string const & target) const;
		int 	meleeAttack(std::string const & target) const;
		int 	takeDamage(unsigned int amount);
		void 	beRepaired(unsigned int amount);
		int 	challengeNewcomer(std::string const & target);

	private:
		ScavTrap(void);

		int 				_hitPoints;
		int const		 	_maxHitPoints;
		int 				_energyPoints;
		int const			_maxEnergyPoints;
		int 				_lvl;
		std::string		 	_name;
		int const 			_meleeAttackDamage;
		int const 			_rangedAttackDamage;
		int const 			_armorDamageReduction;

		int 	_challengeSphinx(std::string const & target) const;
		int 	_challengeBackphabet(std::string const & target) const;
		int 	_challengeElbow(std::string const & target) const;
		int 	_challengeColor(std::string const & target) const;
		int 	_challengeCottonEyed(std::string const & target) const;
		int 	_yesNoLoop(int const count) const;

		typedef int(ScavTrap::*_exe)(std::string const &) const;
		
		_exe 	_exeTab[5] = {&ScavTrap::_challengeSphinx, &ScavTrap::_challengeBackphabet,
			&ScavTrap::_challengeElbow, &ScavTrap::_challengeColor, &ScavTrap::_challengeCottonEyed};
		
};

std::ostream & operator<<(std::ostream &o, ScavTrap const &rhs);

#endif
