/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 20:15:45 by esoulard          #+#    #+#             */
/*   Updated: 2020/12/23 20:43:59 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUPERTRAP_HPP
#define SUPERTRAP_HPP

#include <iostream>
#include "FragTrap.hpp"
#include "NinjaTrap.hpp"

class SuperTrap: public FragTrap, public NinjaTrap {
	
	public:
		SuperTrap(std::string const name);
		SuperTrap(SuperTrap const &src);
		~SuperTrap(void);

		SuperTrap & operator=(SuperTrap const &rhs);

	    using FragTrap::rangedAttack;
	    using NinjaTrap::meleeAttack;

	private:
		SuperTrap(void);
		
};

std::ostream & operator<<(std::ostream &o, SuperTrap const &rhs);

#endif
