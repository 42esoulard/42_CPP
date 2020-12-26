/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 19:54:04 by esoulard          #+#    #+#             */
/*   Updated: 2020/12/11 15:35:54 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"

class HumanB {

public:
	HumanB(std::string name);
	~HumanB(void);

	void 		setWeapon(Weapon &weapon_addr);
	void 		attack(void) const;

private:
	Weapon 		*_weaponPtr;
	std::string	_name;
};

#endif