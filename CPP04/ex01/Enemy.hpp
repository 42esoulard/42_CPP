/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 15:12:17 by esoulard          #+#    #+#             */
/*   Updated: 2020/12/28 19:05:13 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_HPP
#define ENEMY_HPP

#include <iostream>

class Enemy {
	
	public:
		Enemy(int hp, std::string const &type);
		Enemy(Enemy const &src);
		virtual ~Enemy(void);

		Enemy & operator=(Enemy const &rhs);

		std::string 	getType(void) const;
		int 			getHP(void) const;
		virtual void 	takeDamage(int);

	protected:
		Enemy(void);
		int 		_hitPoints;
		std::string	_type;
		
};

std::ostream & operator<<(std::ostream &o, Enemy const &rhs);

#endif