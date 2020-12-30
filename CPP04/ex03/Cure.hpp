/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 16:15:27 by esoulard          #+#    #+#             */
/*   Updated: 2020/12/30 16:16:43 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include <iostream>
#include "AMateria.hpp"

class Cure : public AMateria {
	
	public:
		Cure(void);
		Cure(Cure const &src);
		virtual ~Cure(void);

		Cure & operator=(Cure const &rhs);

		virtual AMateria* 	clone(void) const;
		virtual void 		use(ICharacter& target);

	private:
		
		
};

std::ostream & operator<<(std::ostream &o, Cure const &rhs);

#endif