/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 16:19:29 by esoulard          #+#    #+#             */
/*   Updated: 2020/12/31 12:08:10 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

int main(void) {

	std::cout << "-----INIT MATERIA SOURCE-----" << std::endl;
	IMateriaSource* src = new MateriaSource();
	
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	
	std::cout << std::endl;
	std::cout << "-----CREATE + EQUIP MATERIA-----" << std::endl;
	ICharacter* me = new Character("me");
	
	std::cout << std::endl;
	AMateria* tmp;
	AMateria *toDiscard;

	toDiscard = src->createMateria("ice");
	me->equip(toDiscard);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	std::cout << std::endl;
	std::cout << "-----ALREADY EQUIPED MATERIA-----" << std::endl;
	me->equip(tmp);
	
	std::cout << std::endl;


	std::cout << std::endl;
	ICharacter* bob = new Character("bob");

	std::cout << std::endl;
	std::cout << "-----MATERIA USE-----" << std::endl;
	me->use(0, *bob);
	me->use(1, *bob);

	std::cout << std::endl;
	std::cout << "-----MATERIASOURCE UNKNOWN TYPE-----" << std::endl;
	tmp = src->createMateria("bazinga");

	std::cout << std::endl;
	std::cout << "-----FULL CHARA INVENTORY-----" << std::endl;

	tmp = src->createMateria("ice");
	me->equip(tmp);
	std::cout << std::endl;
	tmp = src->createMateria("cure");
	me->equip(tmp);
	std::cout << std::endl;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	std::cout << std::endl;
	tmp = src->createMateria("cure");
	me->equip(tmp);
	std::cout << std::endl;

	std::cout << std::endl;
	std::cout << "-----FULL MATERIA SOURCE WITH IDENTICAL TYPES-----" << std::endl;
	src->learnMateria(new Ice());
	std::cout << std::endl;
	src->learnMateria(new Ice());
	std::cout << std::endl;
	src->learnMateria(new Ice());
	
	std::cout << std::endl;
	std::cout << "-----UNEQUIP MATERIA-----" << std::endl;
	tmp = src->createMateria("ice");
	bob->equip(tmp);
	bob->use(0, *me);
	bob->unequip(0);

	std::cout << std::endl;
	std::cout << "-----UNEQUIP EMPTY IDX-----" << std::endl;
	bob->unequip(0);

	std::cout << std::endl;
	std::cout << "-----MATERIA TRANSFER BETWEEN CHARACTERS-----" << std::endl;


	me->unequip(0);
	me->equip(tmp);
	std::cout << "-----NOTE THE INCREASED XP UPON USE-----" << std::endl;
	me->use(0, *bob);

	std::cout << std::endl;
	std::cout << "-----DELETION *BOOM NO LEAKS*-----" << std::endl;

	std::cout << std::endl;
	delete toDiscard;
	std::cout << std::endl;
	delete bob;
	std::cout << std::endl;
	delete me;
	std::cout << std::endl;
	delete src;
	
	return 0;
}