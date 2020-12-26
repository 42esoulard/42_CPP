/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 16:39:20 by esoulard          #+#    #+#             */
/*   Updated: 2020/12/22 10:27:07 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <iostream>

class FragTrap {
	
	public:
		FragTrap(std::string const name);
		FragTrap(FragTrap const &src);
		~FragTrap(void);
		FragTrap & operator=(FragTrap const &rhs);

		std::string const 	getName(void) const;
		int const 			getHP(void) const;
		int const 			getEP(void) const;

		int 	rangedAttack(std::string const & target) const;
		int 	meleeAttack(std::string const & target) const;
		int 	takeDamage(unsigned int amount);
		void 	beRepaired(unsigned int amount);
		int 	vaulthunter_dot_exe(std::string const & target);

	private:
		FragTrap(void);

		int 				_hitPoints;
		int const		 	_maxHitPoints;
		int 				_energyPoints;
		int const			_maxEnergyPoints;
		int 				_lvl;
		std::string		 	_name;
		int const 			_meleeAttackDamage;
		int const 			_rangedAttackDamage;
		int const 			_armorDamageReduction;

		int _sleepAttack(std::string const & target) const;
		int _stayAttack(std::string const & target) const;
		int _fatalAttack(std::string const & target) const;
		int _grenadeAttack(std::string const & target) const;
		int _freezeAttack(std::string const & target) const;


		typedef int(FragTrap::*_exe)(std::string const &) const;
		
		_exe 		_exeTab[5] = {&FragTrap::_sleepAttack, &FragTrap::_stayAttack,
			&FragTrap::_fatalAttack, &FragTrap::_grenadeAttack, &FragTrap::_freezeAttack};
		
		std::string	_exeNames[5] = {"Sleep", "Stay", "Fatal", "Grenade", "Freeze"};
};

std::ostream & operator<<(std::ostream &o, FragTrap const &rhs);

#endif
