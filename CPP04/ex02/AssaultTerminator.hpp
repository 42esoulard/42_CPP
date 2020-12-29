/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AssaultTerminator.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 11:36:14 by esoulard          #+#    #+#             */
/*   Updated: 2020/12/29 14:56:25 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASSAULTTERMINATOR_HPP
#define ASSAULTTERMINATOR_HPP

#include <iostream>
#include "ISpaceMarine.hpp"

class AssaultTerminator : public ISpaceMarine {
	
	public:
		AssaultTerminator(void);
		AssaultTerminator(AssaultTerminator const &src);
		~AssaultTerminator(void);

		AssaultTerminator & operator=(AssaultTerminator const &rhs);

		virtual ISpaceMarine* 	clone(void) const;
		virtual void 			battleCry(void) const;
		virtual void 			rangedAttack(void) const;
		virtual void 			meleeAttack(void) const;
};

#endif