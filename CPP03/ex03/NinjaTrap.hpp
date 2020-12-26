/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 16:39:20 by esoulard          #+#    #+#             */
/*   Updated: 2020/12/22 20:13:06 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NinjaTrap_HPP
#define NinjaTrap_HPP

#include <iostream>
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class NinjaTrap: public ClapTrap {
	
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

	private:
		NinjaTrap(void);

};

std::ostream & operator<<(std::ostream &o, NinjaTrap const &rhs);

#endif
