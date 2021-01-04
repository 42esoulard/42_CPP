/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperMutant.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 15:35:40 by esoulard          #+#    #+#             */
/*   Updated: 2021/01/04 18:58:00 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUPERMUTANT_HPP
#define SUPERMUTANT_HPP

#include "Enemy.hpp"
#include <iostream>

class SuperMutant : public Enemy {
	
	public:
		SuperMutant(void);
		SuperMutant(SuperMutant const &src);
		virtual ~SuperMutant(void);

		SuperMutant & 	operator=(SuperMutant const &rhs);

		virtual void 	takeDamage(int);
		
};

#endif