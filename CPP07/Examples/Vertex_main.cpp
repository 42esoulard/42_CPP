/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vertex_main.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 11:59:15 by esoulard          #+#    #+#             */
/*   Updated: 2021/01/12 12:00:45 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Vertex_classT.hpp"

int main(void) {
	
	Vertex<int> 	v1(12, 23, 34);
	Vertex<>		v2(12, 23, 34);

	std::cout << v1 << std::endl;
	std::cout << v2 << std::endl;

	return 0;
}