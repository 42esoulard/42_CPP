/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWeapon.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 13:50:36 by esoulard          #+#    #+#             */
/*   Updated: 2021/01/04 18:57:28 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AWEAPON_HPP
#define AWEAPON_HPP

#include <iostream>

class AWeapon {	

	public:
		AWeapon(std::string const & name, int apcost, int damage);
		AWeapon(AWeapon const &src);
		virtual ~AWeapon(void);
		
		AWeapon & 	operator=(AWeapon const &rhs);

		std::string 	getName(void) const;
		int 			getAPCost(void) const;
		int 			getDamage(void) const;
		virtual void 	attack(void) const = 0;

	protected:
		AWeapon(void);
		std::string 		_name;
		int 				_damage;
		int 				_apCost;
};

std::ostream & operator<<(std::ostream &o, AWeapon const &rhs);

#endif