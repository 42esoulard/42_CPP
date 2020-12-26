/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 11:37:50 by esoulard          #+#    #+#             */
/*   Updated: 2020/12/11 13:44:10 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIEHORDE_HPP
# define ZOMBIEHORDE_HPP

#include "Zombie.hpp"

class ZombieHorde {

	public:

		ZombieHorde(int n);
		~ZombieHorde(void);

		void 	announce(void) const;

	private:

		int 				_count;
		Zombie 				*_horde;

		static std::string 	randNames[10];

};

#endif