/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 12:04:41 by esoulard          #+#    #+#             */
/*   Updated: 2020/12/11 15:39:30 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"

void ponyOnTheStack(void) {

	std::cout << "[ENTERING ponyOnTheStack()]" << std::endl;
	Pony BordeauxStJean = Pony("Bordeaux St Jean on the Stack", "burgundy", "wild");
	
	BordeauxStJean.runLikeTheWind();
	BordeauxStJean.bakeCupcakes();
	BordeauxStJean.breatheFire();

	std::cout << "[IN ponyOnTheStack() before return]" << std::endl;

	return ;
}

void ponyOnTheHeap(void) {

	std::cout << "[ENTERING ponyOnTheHeap()]" << std::endl;
	Pony *GareDAusterlitz = new Pony("Gare D'Austerlitz on the Heap", "golden", "goofy");
	
	GareDAusterlitz->runLikeTheWind();
	GareDAusterlitz->bakeCupcakes();
	GareDAusterlitz->breatheFire();

	std::cout << "[IN ponyOnTheHeap() BEFORE delete]" << std::endl;
	delete GareDAusterlitz;
	std::cout << "[IN ponyOnTheHeap() AFTER delete]" << std::endl;

	return ;
}

int main(void) {

	ponyOnTheStack();
	std::cout << "[AFTER ponyOnTheStack()]" << std::endl << std::endl;
	ponyOnTheHeap();
	std::cout << "[AFTER ponyOnTheHeap()]" << std::endl;

	return 0;
}