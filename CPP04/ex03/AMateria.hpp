/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 14:17:01 by esoulard          #+#    #+#             */
/*   Updated: 2020/12/30 16:13:10 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>

class AMateria {

	public:
		AMateria(std::string const & type);
		
		virtual ~AMateria(void);

		AMateria & operator=(AMateria const &rhs);

		std::string const & getType(void) const; //Returns the materia type
		unsigned int 		getXP(void) const; //Returns the Materia's XP
		virtual AMateria* 	clone(void) const = 0;
		virtual void 		use(ICharacter& target);

	private:
		AMateria(void);
		AMateria(AMateria const &src);
		unsigned int 	_xp;
		std::string 	type;
		

};

#endif