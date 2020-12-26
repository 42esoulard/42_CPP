/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 13:16:03 by esoulard          #+#    #+#             */
/*   Updated: 2020/12/11 15:32:58 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIEEVENT_HPP
# define ZOMBIEEVENT_HPP

#include <iostream>
#include "Zombie.hpp"

class ZombieEvent {

	public:

		ZombieEvent(void);
		~ZombieEvent(void);

		static void 	setZombieType(Zombie *newZombie, std::string type);
		static Zombie 	*newZombie (std::string name);
		static void 	randomChump (void);

	private:

		static std::string randNames[10];

};

#endif