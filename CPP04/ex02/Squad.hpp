/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Squad.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 10:23:31 by esoulard          #+#    #+#             */
/*   Updated: 2020/12/29 13:18:51 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SQUAD_HPP
#define SQUAD_HPP

#include <iostream>
#include "ISquad.hpp"
#include "ISpaceMarine.hpp"

class Unit {
	
	public:
		ISpaceMarine 	*cur;
		Unit 			*next;

};

class Squad : public ISquad {
	
	public:
		Squad(void);
		Squad(Squad const &src);
		virtual ~Squad(void);

		Squad & operator=(Squad const &rhs);

		virtual int getCount(void) const;
		virtual ISpaceMarine* getUnit(int) const;
		virtual int push(ISpaceMarine*);
		
		Unit 	*getUnitList(void) const;



	private:
		int				_unitCount;
		Unit 			*_unitList;//contains first unit
						//units must have next ptr
		
};

std::ostream & operator<<(std::ostream &o, Squad const &rhs);

#endif