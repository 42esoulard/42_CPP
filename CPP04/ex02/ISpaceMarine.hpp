/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ISpaceMarine.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 11:17:50 by esoulard          #+#    #+#             */
/*   Updated: 2020/12/29 11:56:56 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ISPACEMARINE_HPP
#define ISPACEMARINE_HPP

class ISpaceMarine {

	public:
		virtual ~ISpaceMarine(void) {};
		virtual ISpaceMarine* clone(void) const = 0;
		virtual void battleCry(void) const = 0;
		virtual void rangedAttack(void) const = 0;
		virtual void meleeAttack(void) const = 0;
};

#endif