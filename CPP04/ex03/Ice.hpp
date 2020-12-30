/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 16:00:22 by esoulard          #+#    #+#             */
/*   Updated: 2020/12/30 16:16:40 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include <iostream>
#include "AMateria.hpp"

class Ice : public AMateria {
	
	public:
		Ice(void);
		Ice(Ice const &src);
		virtual ~Ice(void);

		Ice & operator=(Ice const &rhs);

		virtual AMateria* 	clone(void) const;
		virtual void 		use(ICharacter& target);

	private:
		
		
};

// std::ostream & operator<<(std::ostream &o, Ice const &rhs);

#endif