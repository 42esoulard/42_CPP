/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex04.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 17:18:24 by esoulard          #+#    #+#             */
/*   Updated: 2020/12/11 15:34:15 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void) {
	
	std::string str = "HI THIS IS BRAIN";
	
	std::string *ptr = &str;
	std::cout << *ptr << std::endl;

	std::string &ref = str;
	std::cout << ref << std::endl;
	
	return 0;
}