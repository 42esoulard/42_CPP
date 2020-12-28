/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RadScorpion.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 15:42:07 by esoulard          #+#    #+#             */
/*   Updated: 2020/12/28 19:04:44 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RADSCORPION_HPP
#define RADSCORPION_HPP

#include "Enemy.hpp"
#include <iostream>

class RadScorpion : public Enemy {
	
	public:
		RadScorpion(void);
		RadScorpion(RadScorpion const &src);
		virtual ~RadScorpion(void);

		RadScorpion & operator=(RadScorpion const &rhs);

};

#endif