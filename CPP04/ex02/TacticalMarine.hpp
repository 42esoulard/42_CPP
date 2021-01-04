/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TacticalMarine.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 11:19:24 by esoulard          #+#    #+#             */
/*   Updated: 2021/01/04 19:37:43 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TACTICALMARINE_HPP
#define TACTICALMARINE_HPP

#include <iostream>
#include "ISpaceMarine.hpp"

class TacticalMarine : public ISpaceMarine {
	
	public:
		TacticalMarine(void);
		TacticalMarine(TacticalMarine const &src);
		virtual ~TacticalMarine(void);

		TacticalMarine & operator=(TacticalMarine const &rhs);

		virtual ISpaceMarine* 	clone(void) const;
		virtual void 			battleCry(void) const;
		virtual void 			rangedAttack(void) const;
		virtual void 			meleeAttack(void) const;
};

#endif