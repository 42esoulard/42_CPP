/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 10:07:37 by esoulard          #+#    #+#             */
/*   Updated: 2020/12/10 12:43:36 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include "ZombieHorde.hpp"

int main(void) {

	ZombieHorde zh = ZombieHorde(10);

	zh.announce();
	std::cout << "In main, before deleting ZombieHorde" << std::endl;

	return 0;
}