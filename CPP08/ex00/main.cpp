/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 17:15:02 by esoulard          #+#    #+#             */
/*   Updated: 2021/01/19 13:07:29 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include "easyfind.hpp"

void displayInt(int i) {
	std::cout << i << std::endl;
}

int	main(void) {

	std::list<int> lst;

	lst.push_back(1234);
	lst.push_back(17);
	lst.push_back(42);
	lst.push_back(50);
	lst.push_back(12);
	lst.push_back(17);

	std::list<int>::const_iterator tmp;
	try {

		std::cout << "LIST: " << std::endl;
		for_each(lst.begin(), lst.end(), displayInt);
		std::cout << "--------" << std::endl;

		tmp = easyfind(lst, 1234);
		std::cout << *tmp << std::endl;
		tmp = easyfind(lst, 17);
		std::cout << *tmp << std::endl;
		std::cout << "(the one right after " << *(--tmp) << ")" << std::endl;
		tmp = easyfind(lst, 192);
		std::cout << *tmp << std::endl;

	}
	catch(std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << "-----------------------" << std::endl;

	std::vector<int> vct;

	vct.push_back(1234);
	vct.push_back(17);
	vct.push_back(42);
	vct.push_back(50);
	vct.push_back(12);
	vct.push_back(17);

	std::vector<int>::const_iterator vit;
	try {

		std::cout << "VECTOR: " << std::endl;
		for_each(vct.begin(), vct.end(), displayInt);
		std::cout << "--------" << std::endl;

		vit = easyfind(vct, 1234);
		std::cout << *vit << std::endl;
		vit = easyfind(vct, 17);
		std::cout << *vit << std::endl;
		std::cout << "(the one right after " << *(--vit) << ")" << std::endl;
		vit = easyfind(vct, 192);
		std::cout << *vit << std::endl;

	}
	catch(std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	return 0;
}