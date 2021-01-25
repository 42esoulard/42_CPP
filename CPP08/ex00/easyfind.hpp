/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 17:15:24 by esoulard          #+#    #+#             */
/*   Updated: 2021/01/25 10:47:47 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <memory>
#include "customException.hpp"

template <typename Container>
typename Container::const_iterator easyfind(Container const &var1, int const var2) {

	typename Container::const_iterator it;
	typename Container::const_iterator ite = var1.end();
	
	for (it = var1.begin(); it != ite; it++) {
	 	if (*it == var2)
	 		return it;
	}
	throw customException("Couldn't find value");
}

#endif

