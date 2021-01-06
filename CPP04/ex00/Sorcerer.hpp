/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 10:52:50 by esoulard          #+#    #+#             */
/*   Updated: 2021/01/05 20:01:28 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORCERER_HPP
#define SORCERER_HPP

#include <iostream>
#include "Victim.hpp"

class Sorcerer {
	
	public:
		Sorcerer(std::string const &name, std::string const &title);
		Sorcerer(Sorcerer const &src);
		~Sorcerer(void);

		Sorcerer & 			operator=(Sorcerer const &rhs);
		std::string const 	&getName(void) const;
		std::string const 	&getTitle(void) const;
	 	void 				polymorph(Victim const &) const;

	private:
		Sorcerer(void);
		std::string  _name;
		std::string  _title;

		
};

std::ostream & operator<<(std::ostream &o, Sorcerer const &rhs);

#endif