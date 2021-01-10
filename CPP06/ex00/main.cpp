/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 10:53:26 by esoulard          #+#    #+#             */
/*   Updated: 2021/01/10 14:43:32 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include "customException.hpp"
#include "Convert.hpp"



int main (int ac, char **av) {

	if (ac != 2) {
		std::cerr << "One parameter required!" << std::endl;
		return 1;
	}

	try {
		int type;
		std::string input(av[1]);

		Convert test(input);
	    
	}
	catch(std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
    
	return 0;
}