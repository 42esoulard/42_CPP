/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 16:39:20 by esoulard          #+#    #+#             */
/*   Updated: 2020/12/23 20:40:25 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap {
	
	public:
		ScavTrap(std::string const name);
		ScavTrap(ScavTrap const &src);
		~ScavTrap(void);
		ScavTrap & operator=(ScavTrap const &rhs);

		int 	rangedAttack(std::string const & target) const;
		int 	meleeAttack(std::string const & target) const;
		int 	challengeNewcomer(std::string const & target);

	private:
		ScavTrap(void);

		int 	_challengeSphinx(std::string const & target) const;
		int 	_challengeBackphabet(std::string const & target) const;
		int 	_challengeElbow(std::string const & target) const;
		int 	_challengeColor(std::string const & target) const;
		int 	_challengeCottonEyed(std::string const & target) const;
		int 	_yesNoLoop(int const count) const;
		

		typedef int(ScavTrap::*_exe)(std::string const &) const;
		_exe 	_exeTab[5] = {&ScavTrap::_challengeSphinx, &ScavTrap::_challengeBackphabet,
			&ScavTrap::_challengeElbow, &ScavTrap::_challengeColor, &ScavTrap::_challengeCottonEyed};
		
};

std::ostream & operator<<(std::ostream &o, ScavTrap const &rhs);

#endif
