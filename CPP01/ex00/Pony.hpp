/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 12:04:06 by esoulard          #+#    #+#             */
/*   Updated: 2020/12/11 13:44:34 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PONY_HPP
# define PONY_HPP

#include <iostream> 

class Pony {

	public:

		Pony(std::string name, std::string color, std::string mood);
		~Pony(void);

		void runLikeTheWind(void) const;
		void bakeCupcakes(void) const;
		void breatheFire(void) const;

	private:

		std::string _name;
		std::string _color;
		std::string _mood;

};

#endif
