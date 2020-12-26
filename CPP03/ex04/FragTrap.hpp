/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 16:39:20 by esoulard          #+#    #+#             */
/*   Updated: 2020/12/23 20:37:48 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class FragTrap: virtual public ClapTrap {
	
	public:
		FragTrap(std::string const name);
		FragTrap(FragTrap const &src);
		~FragTrap(void);
		FragTrap & operator=(FragTrap const &rhs);

		int 	rangedAttack(std::string const & target) const;
		int 	meleeAttack(std::string const & target) const;
		int 	vaulthunter_dot_exe(std::string const & target);

	protected:
		FragTrap(void);

		int _sleepAttack(std::string const & target) const;
		int _stayAttack(std::string const & target) const;
		int _fatalAttack(std::string const & target) const;
		int _grenadeAttack(std::string const & target) const;
		int _freezeAttack(std::string const & target) const;
		

		typedef int(FragTrap::*_exe)(std::string const &) const;
		_exe 		_exeTab[5] = {&FragTrap::_sleepAttack, &FragTrap::_stayAttack,
			&FragTrap::_fatalAttack, &FragTrap::_grenadeAttack, &FragTrap::_freezeAttack};
		
		std::string	_exeNames[5] = {"Sleep", "Stay", "Fatal", "Grenade", "Freeze"};
};

std::ostream & operator<<(std::ostream &o, FragTrap const &rhs);

#endif
