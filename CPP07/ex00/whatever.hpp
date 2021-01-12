/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 14:31:49 by esoulard          #+#    #+#             */
/*   Updated: 2021/01/12 14:40:37 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template< typename T>
void swap(T &x, T &y) {
	
	T tmp;

	tmp =  x;
	x = y;
	y = tmp;
}

template< typename T>
T const & min(T const &x, T const &y) {

	return (x<y ? x : y);
}

template< typename T>
T const & max(T const &x, T const &y) {

	return (x>y ? x : y);
}

#endif