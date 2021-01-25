/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 17:15:24 by esoulard          #+#    #+#             */
/*   Updated: 2021/01/25 11:19:03 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include "customException.hpp"

template <typename Container>
typename Container::const_iterator easyfind(Container const &var1, int const var2) {

	typename Container::const_iterator it;

	it = std::find(var1.begin(), var1.end(), var2);
	if (it == var1.end())
		throw customException("Couldn't find value");
	return (it);
}

#endif
