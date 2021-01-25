/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 17:15:24 by esoulard          #+#    #+#             */
/*   Updated: 2021/01/25 13:49:24 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include "customException.hpp"

template <typename C>
typename C::const_iterator easyfind(C const &var1, int const var2) {

	typename C::const_iterator it;

	it = std::find(var1.begin(), var1.end(), var2);
	if (it == var1.end())
		throw customException("Couldn't find value");
	return (it);
}

#endif
