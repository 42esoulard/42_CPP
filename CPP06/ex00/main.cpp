/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 10:53:26 by esoulard          #+#    #+#             */
/*   Updated: 2021/01/09 13:43:36 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include "customException.hpp"
#include "Convert.hpp"

#define T_INVALID	-1

int main (int ac, char **av) {

	try {

		int type;

		std::string input(av[1]);

		Convert test(input);
		std::cout << test << std::endl;
	    
	}
	catch(std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
    
	return 0;
}