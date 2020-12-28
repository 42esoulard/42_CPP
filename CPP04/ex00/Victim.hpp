/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 10:53:57 by esoulard          #+#    #+#             */
/*   Updated: 2020/12/28 12:23:46 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VICTIM_HPP
#define VICTIM_HPP

#include <iostream>

class Victim {
	
	public:
		Victim(std::string const &name);
		Victim(Victim const &src);
		~Victim(void);

		Victim & 			operator=(Victim const &rhs);
		std::string const	getName(void) const;
		virtual void 		getPolymorphed(void) const;

	protected:
		std::string const _name;
		Victim(void);
		
};

std::ostream & operator<<(std::ostream &o, Victim const &rhs);

#endif