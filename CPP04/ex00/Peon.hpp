/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Peon.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 11:46:17 by esoulard          #+#    #+#             */
/*   Updated: 2020/12/28 12:23:27 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PEON_HPP
#define PEON_HPP

#include <iostream>
#include "Victim.hpp"

class Peon : public Victim {
	
	public:
		Peon(std::string const &name);
		Peon(Peon const &src);
		~Peon(void);

		Peon & 			operator=(Peon const &rhs);
		virtual void 	getPolymorphed(void) const;

	private:
		Peon(void);
		
};

#endif