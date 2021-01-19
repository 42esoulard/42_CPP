/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 17:15:24 by esoulard          #+#    #+#             */
/*   Updated: 2021/01/19 12:27:14 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <memory>
#include "customException.hpp"

//template <containerTemplate<int, nextT> classT>

/* 
** easyFind() prototype:
** takes a T<int, nextT>
** returns an iterator on T<int, next> and an int
*/
template <template <typename, typename> class T>
typename T<int, std::allocator<int>>::const_iterator easyfind(T<int, std::allocator<int>> const &var1, int const var2) {

	typename T<int, std::allocator<int>>::const_iterator it;
	typename T<int, std::allocator<int>>::const_iterator ite = var1.end();
	
	for (it = var1.begin(); it != ite; it++) {
	 	if (*it == var2)
	 		return it;
	}
	throw customException("Couldn't find value");
}

#endif

