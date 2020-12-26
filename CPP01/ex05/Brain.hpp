/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 17:25:58 by esoulard          #+#    #+#             */
/*   Updated: 2020/12/11 13:43:52 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>
#include <sstream>

class Brain {

	public:
		Brain();
		~Brain();

		std::string identify(void) const;

	private:
		int 		sizeInCm;
		std::string	color;
		std::string	smell;
};

#endif 