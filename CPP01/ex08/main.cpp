/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 13:41:37 by esoulard          #+#    #+#             */
/*   Updated: 2020/12/11 15:39:00 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"

int main(void) {
	
	Human Bob;
	const std::string action[] = {"meleeAttack", "rangedAttack", "intimidatingShout"};

	Bob.action(action[0], std::string("Frank"));
	Bob.action(action[1], std::string("Frank"));
	Bob.action(action[2], std::string("Frank"));

	return 0;
}