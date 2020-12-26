/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 19:44:01 by esoulard          #+#    #+#             */
/*   Updated: 2020/12/11 15:35:06 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"

class HumanA {

public:
	HumanA(std::string name, Weapon &weaponAddr);
	~HumanA(void);

	void 		attack(void) const;

private:
	Weapon 		&_weaponRef;
	std::string	_name;
};

#endif