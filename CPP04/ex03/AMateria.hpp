/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 14:17:01 by esoulard          #+#    #+#             */
/*   Updated: 2020/12/30 14:26:23 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>

class AMateria {

	public:
		AMateria(std::string const & type);
		AMateria(AMateria const &src);
		~AMateria(void);

		AMateria & operator=(AMateria const &rhs);

		std::string const & getType(void) const; //Returns the materia type
		unsigned int 		getXP(void) const; //Returns the Materia's XP
		virtual AMateria* 	clone(void) const = 0;
		virtual void 		use(ICharacter& target);

	private:
		[...]
		unsigned int _xp;
		AMateria(void);

};

#endif