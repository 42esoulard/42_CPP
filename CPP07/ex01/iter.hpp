/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 18:12:21 by esoulard          #+#    #+#             */
/*   Updated: 2021/01/14 13:19:36 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

template<typename T>
void iter(T *addr, size_t size, void (&function)(T &)) {
	
	if (addr) {
		for (int i = 0; i < size; i++)
			function(addr[i]);
	}
}

template<typename T>
void multiply(T &elem) {

	elem *= 2;
}

template<typename T>
void increment(T &elem) {

	elem++;
}

template<typename T>
void read(T &elem) {

	std::cout << elem << std::endl;
}

#endif