/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 16:39:20 by esoulard          #+#    #+#             */
/*   Updated: 2020/12/23 20:40:04 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NINJATRAP_HPP
#define NINJATRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class NinjaTrap: virtual public ClapTrap {
	
	public:
		NinjaTrap(std::string const name);
		NinjaTrap(NinjaTrap const &src);
		~NinjaTrap(void);
		NinjaTrap & operator=(NinjaTrap const &rhs);

		int 	rangedAttack(std::string const & target) const;
		int 	meleeAttack(std::string const & target) const;

		int 	ninjaShoebox(FragTrap const &fTrap) const;
		int 	ninjaShoebox(ScavTrap const &sTrap) const;
		int 	ninjaShoebox(NinjaTrap const &nTrap) const;

	protected:
		NinjaTrap(void);

};

std::ostream & operator<<(std::ostream &o, NinjaTrap const &rhs);

#endif
