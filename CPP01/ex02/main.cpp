/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 10:07:37 by esoulard          #+#    #+#             */
/*   Updated: 2020/12/10 10:44:02 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include "ZombieEvent.hpp"

int main(void) {

	Zombie *heapZombie = ZombieEvent::newZombie("Bob");

	heapZombie->announce();
	std::cout << "In main, before deleting heapZombie" << std::endl;
	delete heapZombie;

	ZombieEvent::randomChump();
	std::cout << "In main, after stackZombie cycle" << std::endl;

	return 0;
}