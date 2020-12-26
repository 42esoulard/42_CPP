/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 07:40:45 by esoulard          #+#    #+#             */
/*   Updated: 2020/12/02 11:50:09 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Contact.hpp"

int main(int ac, char **av) {
	
	std::string	in;
	Contact 	phonebook[9];

	while (1) {
		std::cout << std::endl << "Press ADD, SEARCH or EXIT..." << std::endl << std::endl;
		std::cin.clear();
		getline(std::cin, in);
		if (in.compare("ADD") == 0)
			Contact::Add(phonebook);
		else if (in.compare("SEARCH") == 0)
			Contact::Search(phonebook);
		else if (in.compare("EXIT") == 0)
			break ;
		else
			std::cout << std::endl << "Bless you! Oh that wasn't a sneeze? I didn't get what you"
			<< " said then, sorry." << std::endl << std::endl;
	}
	return 0;
}
