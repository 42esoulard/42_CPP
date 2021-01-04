/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 10:53:57 by esoulard          #+#    #+#             */
/*   Updated: 2021/01/04 18:56:22 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VICTIM_HPP
#define VICTIM_HPP

#include <iostream>

class Victim {
	
	public:
		Victim(std::string const &name);
		Victim(Victim const &src);
		virtual ~Victim(void);

		Victim & 			operator=(Victim const &rhs);
		std::string const	getName(void) const;
		virtual void 		getPolymorphed(void) const;

	protected:
		std::string  _name;
		Victim(void);
		
};

std::ostream & operator<<(std::ostream &o, Victim const &rhs);

#endif