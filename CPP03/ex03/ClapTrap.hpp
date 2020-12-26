/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 13:27:18 by esoulard          #+#    #+#             */
/*   Updated: 2020/12/23 20:55:59 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
 
 #ifndef CLAPTRAP_HPP
 #define CLAPTRAP_HPP

#include <iostream>

class ClapTrap {
	
	public:
		ClapTrap(void);
		ClapTrap(ClapTrap const &src);
		~ClapTrap(void);

		ClapTrap & operator=(ClapTrap const &rhs);

		std::string const 	getName(void) const;
		int const 			getHP(void) const;
		int const 			getEP(void) const;

		int 	takeDamage(unsigned int amount);
		void 	beRepaired(unsigned int amount);

	protected:
		int 				_hitPoints;
		int 			 	_maxHitPoints;
		int 				_energyPoints;
		int 				_maxEnergyPoints;
		int 				_lvl;
		std::string		 	_name;
		int 	 			_meleeAttackDamage;
		int 	 			_rangedAttackDamage;
		int 	 			_armorDamageReduction;
		
};

 #endif