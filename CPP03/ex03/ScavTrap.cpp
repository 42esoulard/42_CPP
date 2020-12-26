/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 16:39:01 by esoulard          #+#    #+#             */
/*   Updated: 2020/12/23 21:04:06 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>
#include <algorithm>

ScavTrap::ScavTrap(void) {

	std::cerr << "[SC4V-TP default constructor called]" << std::endl;
};

ScavTrap::ScavTrap(std::string const name) {

	this->_name = name;
	this->_maxHitPoints = 100; 
	this->_maxEnergyPoints = 50; 
	this->_meleeAttackDamage = 20; 
	this->_rangedAttackDamage = 15; 
	this->_armorDamageReduction = 3; 
	this->_hitPoints = this->_maxHitPoints;
	this->_energyPoints = this->_maxEnergyPoints;
	this->_lvl = 1;
	std::cerr << "[SC4V-TP " << this->_name << " created]: Let's get this party started!" << std::endl;
};

ScavTrap::ScavTrap(ScavTrap const &src) {

	std::cerr << "[SC4V-TP copy constructor called]" << std::endl;
	*this = src;
};

ScavTrap::~ScavTrap(void) {

	std::cerr << "[SC4V-TP " << this->_name << " destroyed]" << std::endl;
};

ScavTrap & ScavTrap::operator=(ScavTrap const &rhs) {

	std::cout << "Assignation operator called" << std::endl;
	this->_maxHitPoints = 100; 
	this->_maxEnergyPoints = 50; 
	this->_meleeAttackDamage = 20; 
	this->_rangedAttackDamage = 15; 
	this->_armorDamageReduction = 3; 
	this->_name = rhs.getName();
	this->_hitPoints = rhs.getHP();
	this->_energyPoints = rhs.getEP();
	this->_lvl = rhs._lvl;

	return *this;
};

//PRINT STATS
std::ostream & operator<<(std::ostream &o, ScavTrap const &rhs) {

	o << "[SC4V-TP " << rhs.getName() << " | HP: " << rhs.getHP() 
	<< "/100 | EP: " << rhs.getEP() << "/50]" << std::endl;
};

//<RANGED ATTACK>, returns <DAMAGES CAUSED>
int ScavTrap::rangedAttack(std::string const & target) const {

	std::cerr << std::endl;
	std::cerr << "[SC4V-TP " << this->_name << " attacks " << target << " at range, causing "
	<< this->_rangedAttackDamage << " points of damage!]" << std::endl;

	std::cerr << "[" << this->_name << "]: You're listening to 'Short-Range Damage Radio'." << std::endl;

	return this->_rangedAttackDamage;
};

//<MELEEATTACK>, returns <DAMAGES CAUSED>
int ScavTrap::meleeAttack(std::string const & target) const {

	std::cerr << std::endl;
	std::cerr << "[SC4V-TP " << this->_name << " attacks " << target << " with a melee attack, causing "
	<< this->_meleeAttackDamage << " points of damage!]" << std::endl;
	std::cerr << "[" << this->_name << "]: Heyyah!" << std::endl;

	return this->_meleeAttackDamage;
};

//<RANDOM CHALLENGE>, -25 EP, returns <DAMAGES CAUSED>
int ScavTrap::challengeNewcomer(std::string const & target) {

	std::cout << std::endl;

	if (this->_energyPoints < 25) {
		std::cout << "[" << this->_name << "]: Crap, no more energy left!" << std::endl;
		return 0;
	}
	this->_energyPoints -= 25;
	
	std::cout << "[SC4V-TP " << this->_name << " IS CHALLENGING NEWCOMER "
	<< target << "!]" << std::endl; 

	int damage = (this->*_exeTab[rand() % 5])(target);

	if (damage == 0)
		std::cout << "[" << target << " resolved the challenge without a single scratch]" << std::endl;
	else
		std::cout << "[" << target << " suffered " << damage << " points of damage!]" << std::endl;

   	return damage;
};

//-------------------------------------------------
//<YES/NO MENU LOOP>
int ScavTrap::_yesNoLoop(int const count) const {

	std::string answer;

	if (count == 0) {
		std::cout <<  "[" << this->_name << "]: That was your last chance.. Now go! Shoo!" << std::endl;
		return 1;
	}

	std::cout << "[" << this->_name << "]: Try again? <yes/no>" << std::endl;
	getline(std::cin, answer);
	std::transform(answer.begin(), answer.end(), answer.begin(), ::tolower);
	
	while (answer.compare("yes") != 0 && answer.compare("no") != 0) {
		std::cout << "[" << this->_name << "]: ...wait.. i'll just.. i'll just try louder.." << std::endl;
		std::cout << "DO YOU WANT TO TRY AGAIN? YES OR NO?" << std::endl;
		getline(std::cin, answer);
		std::transform(answer.begin(), answer.end(), answer.begin(), ::tolower);
	}

	if (answer.compare("no") == 0) {
		std::cout <<  "[" << this->_name << "]: HAHA you have been DEAFEATED by my GREAT POWERS!!" << std::endl;
		return 1;
	}
	return 0;
}

//SPHINX CHALLENGE, 30 DAMAGE
int ScavTrap::_challengeSphinx(std::string const & target) const {
	
	std::string answer = "";
	int 		count = 3;
	int 		damage = 30;

	std::cout << "[" << this->_name << "]: Won't you look at my beauuutiful sphinx paws!!" << std::endl;
	std::cout << "Ahem.. I mean.. Hi " << target << ", answer my riddle and you may enter:" << std::endl;

	std::cout << "What goes on four feet in the morning, two feet at noon, and three feet in the evening?" << std::endl;
	getline(std::cin, answer);
	std::transform(answer.begin(), answer.end(), answer.begin(), ::tolower);

	while (count > 0 && answer.compare("man") != 0 &&
		answer.compare("a person") != 0 && answer.compare("human") != 0 &&
		answer.compare("a human") != 0 && answer.compare("a man") != 0) {

		std::cout <<  "[" << this->_name << "]: Ouch, wrong answer!" << std::endl;
		count--;
		if (this->_yesNoLoop(count) != 0)
			return damage;

		std::cout << "[You have " << count << " tries left]" << std::endl;
		std::cout <<  "[" << this->_name << "]: What goes on four feet in the morning, two feet at noon, and three feet in the evening?" << std::endl;
		getline(std::cin, answer);
		std::transform(answer.begin(), answer.end(), answer.begin(), ::tolower);
	}
	
	std::cout <<  "[" << this->_name << "]: Omg that's right! NOOOO I'M MELTIIIIING.. Jk, you can enter, make yourself at home!" << std::endl;
	return 0;
};

//Backwards Alphabet CHALLENGE, 10 DAMAGE
int ScavTrap::_challengeBackphabet(std::string const & target) const {
	
	std::string answer = "";
	int 		count = 3;
	int 		damage = 10;

	std::cout << "[" << this->_name << "]: BEEP BOOP, INTRUDER!" << std::endl;
	std::cout << "TELL ME YOUR NAME, " << target << "!.. Uh.. ok, seems like i already know it, so.." << std::endl;
	
	std::cout << "Gimme your best backwards alphabet!!" << std::endl;
	getline(std::cin, answer);
	std::transform(answer.begin(), answer.end(), answer.begin(), ::tolower);

	while (count > 0 && answer.compare("zyxwvutsrqponmlkjihgfedcba") != 0) {
		
		std::cout <<  "[" << this->_name << "]: Ouch, wrong answer!" << std::endl;
		count--;
		if (this->_yesNoLoop(count) != 0)
			return damage;

		std::cout << "[You have " << count << " tries left]" << std::endl;
		std::cout <<  "[" << this->_name << "]: Gimme your best backwards alphabet!!" << std::endl;
		getline(std::cin, answer);
		std::transform(answer.begin(), answer.end(), answer.begin(), ::tolower);
	}
	
	std::cout <<  "[" << this->_name << "]: Omg that's right! NOOOO I'M MELTIIIIING.. Jk, you can enter, make yourself at home!" << std::endl;
	return 0;
};

//ELBOW LICKING CHALLENGE, 40 DAMAGE (or 80 if LIAR)
int ScavTrap::_challengeElbow(std::string const & target) const {

	std::string answer = "";
	int 		count = 3;
	int 		damage = 40;

	std::cout << "[" << this->_name << "]: BEEP BOOP, INTRUDER!" << std::endl;
	std::cout << "Hey, " << target << "! What do you think of my elbows?" << std::endl;
	
	std::cout << "Bet you can't even lick yours!! Can you? <yes/no>" << std::endl;
	getline(std::cin, answer);
	std::transform(answer.begin(), answer.end(), answer.begin(), ::tolower);

	while (count > 0 && answer.compare("yes") != 0 && answer.compare("no") != 0) {
		
		std::cout << "...Wait, wut?" << std::endl;
		count--;
		if (this->_yesNoLoop(count) != 0)
			return damage;

		std::cout << "[You have " << count << " tries left]" << std::endl;
		std::cout <<  "[" << this->_name << "]: Bet you can't even lick your elbow!! Can you? <yes/no>" << std::endl;
		getline(std::cin, answer);
		std::transform(answer.begin(), answer.end(), answer.begin(), ::tolower);
	}

	if (answer.compare("yes") == 0) {
		std::cout <<  "[" << this->_name << "]: LIAR LIAR PANTS ON FIRE!! YOU GET DOUBLE DAMAGE AND ETERNAL SHAME!!" << std::endl;
		return damage * 2;
	}

	if (answer.compare("no") == 0)
		std::cout <<  "[" << this->_name << "]: Well at least you're honest. Now shoo!!" << std::endl;
	return damage;
};

//BOB ROSS CHALLENGE, 20 DAMAGE
int ScavTrap::_challengeColor(std::string const & target) const {
	
	std::string answer = "";
	int 		count = 3;
	int 		damage = 20;

	std::cout << "[" << this->_name << "]: Brushie brushie.." << std::endl;
	std::cout << "Ahem.. I mean.. Hi " << target << ".. Pff, i was waiting for Bob Ross. This is underwhelming." << std::endl;

	std::cout << "I bet he would guess my favourite colour in the blink of an eye. Can you?" << std::endl;
	getline(std::cin, answer);
	std::transform(answer.begin(), answer.end(), answer.begin(), ::tolower);

	while (count > 0 && answer.compare("cadmium yellow") != 0) {

		std::cout <<  "[" << this->_name << "]: Wrong answer.. C'mon, channel your inner Bob Ross, you can do it!" << std::endl;
		count--;
		if (this->_yesNoLoop(count) != 0)
			return damage;
		std::cout << "[You have " << count << " tries left]" << std::endl;
		std::cout <<  "[" << this->_name << "]: What's my favourite colour?" << std::endl;
		getline(std::cin, answer);
		std::transform(answer.begin(), answer.end(), answer.begin(), ::tolower);
	}
	
	std::cout <<  "[" << this->_name << "]: Weee now come in, let's paint happy little trees together!!!" << std::endl;
	return 0;
};

//COWBOY CHALLENGE, 50 DAMAGE
int ScavTrap::_challengeCottonEyed(std::string const & target) const {

	std::string answer = "";
	int 		count = 3;
	int 		damage = 50;

	std::cout << "[" << this->_name << "]: Where did ya come from, where did ya goooooo" << std::endl;
	std::cout << "Ahem.. I mean.. Hi " << target << ".." << std::endl;

	std::cout << "If it hadn't been for Cotton Eyed Joe, when would have I been married?" << std::endl;
	getline(std::cin, answer);
	std::transform(answer.begin(), answer.end(), answer.begin(), ::tolower);

	while (count > 0 && answer.compare("a long time ago") != 0) {

		std::cout <<  "[" << this->_name << "]: Ouch, wrong answer!" << std::endl;
		count--;
		if (this->_yesNoLoop(count) != 0)
			return damage;

		std::cout << "[You have " << count << " tries left]" << std::endl;
		std::cout << "[" << this->_name << "]: If it hadn't been for Cotton Eyed Joe, when would have I been married?" << std::endl;
		getline(std::cin, answer);
		std::transform(answer.begin(), answer.end(), answer.begin(), ::tolower);
	}
	
	std::cout << "Yeeeeeehaaaaaw!! C'mon in cowboy, make yourself at home!" << std::endl;
	return 0;
};
//-------------------------------------------------
