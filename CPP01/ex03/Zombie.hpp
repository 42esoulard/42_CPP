/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 13:07:43 by esoulard          #+#    #+#             */
/*   Updated: 2020/12/11 13:44:07 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class Zombie {

	public:

		Zombie(void);
		~Zombie(void);

		void 		announce(void) const;
		void 		setName(std::string name);
		void 		setType(std::string type);

	private:
		std::string _type;
		std::string _name;

};

#endif