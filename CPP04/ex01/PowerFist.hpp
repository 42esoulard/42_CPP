/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PowerFist.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 14:21:32 by esoulard          #+#    #+#             */
/*   Updated: 2020/12/28 19:04:53 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POWERFIST_HPP
#define POWERFIST_HPP

#include "AWeapon.hpp"
#include <iostream>

class PowerFist : public AWeapon {
	
	public:
		PowerFist(void);
		PowerFist(PowerFist const &src);
		~PowerFist(void);

		PowerFist &		operator=(PowerFist const &rhs);
		
		virtual void	attack(void) const;
};

#endif