/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 19:34:35 by esoulard          #+#    #+#             */
/*   Updated: 2020/12/10 20:16:07 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>

class Weapon {

public:
	Weapon(std::string type);
	~Weapon(void);

	const std::string	&getType(void) const;
	void 				setType(std::string type);

private:
	std::string 		_type;

};

#endif