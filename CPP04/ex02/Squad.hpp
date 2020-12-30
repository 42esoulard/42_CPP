/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Squad.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 10:23:31 by esoulard          #+#    #+#             */
/*   Updated: 2020/12/30 13:47:50 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SQUAD_HPP
#define SQUAD_HPP

#include <iostream>
#include "ISquad.hpp"
#include "ISpaceMarine.hpp"

typedef struct t_Unit {

		ISpaceMarine 	*cur;
		t_Unit 			*next;

}				Unit;

class Squad : public ISquad {
	
	public:

		Squad(void);
		Squad(Squad const &src);
		virtual ~Squad(void);

		Squad & operator=(Squad const &rhs);

		virtual int getCount(void) const;
		virtual ISpaceMarine* getUnit(int) const;
		virtual int push(ISpaceMarine*);
		
		Unit 	&copyUnitList(void) const;
		void 	deleteUnitList(void);



	private:

		int				_unitCount;
		Unit 			*_unitList;
		
};

#endif