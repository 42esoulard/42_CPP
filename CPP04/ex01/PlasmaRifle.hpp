/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PlasmaRifle.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 14:20:25 by esoulard          #+#    #+#             */
/*   Updated: 2021/01/04 18:50:42 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLASMARIFLE_HPP
#define PLASMARIFLE_HPP

#include "AWeapon.hpp"
#include <iostream>

class PlasmaRifle : public AWeapon {
	
	public:
		PlasmaRifle(void);
		PlasmaRifle(PlasmaRifle const &src);
		virtual ~PlasmaRifle(void);

		PlasmaRifle & 	operator=(PlasmaRifle const &rhs);
		
		 void 	attack(void) const;
};

#endif