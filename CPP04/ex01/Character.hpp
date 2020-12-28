/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 15:45:28 by esoulard          #+#    #+#             */
/*   Updated: 2020/12/28 19:05:27 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "Character.hpp"
#include "AWeapon.hpp"
#include "Enemy.hpp"
#include <iostream>

class Character {
	
	public:
		Character(std::string const & name);
		Character(Character const &src);
		~Character(void);

		Character & operator=(Character const &rhs);

		void 		recoverAP(void);
		void 		equip(AWeapon*);
		void 		attack(Enemy*&);
		std::string getName(void) const;
		int			getAP(void) const;
		AWeapon		*getWeapon(void) const;

	private:
		Character(void);
		std::string _name;
		int 		_actionPoints;
		AWeapon		*_weapon;
		
};

std::ostream & operator<<(std::ostream &o, Character const &rhs);

#endif