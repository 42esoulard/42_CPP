/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 16:23:36 by esoulard          #+#    #+#             */
/*   Updated: 2020/12/30 16:34:35 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include <iostream>

class Character {
	
	public:
		
		Character(Character const &src);
		~Character(void);

		Character & operator=(Character const &rhs);

		virtual std::string const & getName(void) const;
		virtual void equip(AMateria* m);
		virtual void unequip(int idx);
		virtual void use(int idx, ICharacter& target);

	private:
		Character(void);
		AMateria	*_inventory[4];
		std::string name;
		
};

// std::ostream & operator<<(std::ostream &o, Character const &rhs);

#endif