/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 14:52:09 by esoulard          #+#    #+#             */
/*   Updated: 2020/12/01 12:42:34 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "Contact.hpp"

Contact::Contact() {
	return;
};

Contact::~Contact(void){
	return;
};

void 		Contact::fillContact(void) {

	std::cout << std::endl << "Oooh you got a new FRIEND :D Good for you!!" << std::endl;
	std::cout << "What's their <FIRSTNAME>?" << std::endl;
	getline(std::cin, this->_firstname);

	std::cout << std::endl << "Aw that's too sweet. Now would you mind " << std::endl
				<< "telling me their <LASTNAME>?" << std::endl;
	getline(std::cin, this->_lastname);

	std::cout << std::endl << "How peculiar! C'mon show them love, let's " << std::endl
				<< "give them a cute <NICKNAME>!" << std::endl;
	getline(std::cin, this->_nickname);

	std::cout << std::endl << "No way they're 42 students too?? Gimme their " << std::endl
				<< "<LOGIN>, I wanna see their cute face!" << std::endl;
	getline(std::cin, this->_login);

	std::cout << std::endl << "My my.. what a sight..! Any chance you know " << std::endl
				<< "where their <POSTAL ADRESS>? For non-creepy purposes?" << std::endl;
	getline(std::cin, this->_postal);

	std::cout << std::endl << "Aww that's too far for my tiny phonebook paws. " << std::endl
				<< "Can I have their <EMAIL>? Still for non-creepy purposes.." << std::endl;
	getline(std::cin, this->_email);

	std::cout << std::endl << "..You're right, that was kinda creepy. I " << std::endl
				<< "guess since I'm a phonebook I should stick to my stupid job " << std::endl
				<< "and just ask for their stupid <PHONE NUMBER>?" << std::endl;
	getline(std::cin, this->_phone);

	std::cout << std::endl << "....yea that's boooooriiiiiiiiing c'mon gimme " << std::endl
				<< "their <BIRTHDAY> I wanna partyyyyy" << std::endl;
	getline(std::cin, this->_bday);

	std::cout << std::endl << "I'll even cook their <FAVOURITE MEAL>, what " << std::endl
				<< "is it?" << std::endl;
	getline(std::cin, this->_favMeal);

	std::cout << std::endl << "Hm I've been wondering.. Just out of curiosity " << std::endl
				<< ".. Any chance you know what is the <COLOR OF THEIR UNDERWEAR>? " << std::endl
				<< "For science ofc.." << std::endl;
	getline(std::cin, this->_underwear);

	std::cout << std::endl << "Fascinating.. now feed me their deepest <DARKEST " << std::endl
				<< "SECRET>.." << std::endl;
	getline(std::cin, this->_secret);

	std::cout << std::endl << "Delicious.. We are now ready for the ritual.. I " << std::endl
				<< "mean the blackmail.. I mean *BEEP BOOP CONTACT SAVED BEEP*" << std::endl;

	if (Contact::_total < 8)
		Contact::_total++;
};

void 		Contact::phonebookFull(Contact *phonebook) {

	std::string in = "";
	int 		index;

	std::cout << std::endl << "I'm just a smaaaall boook, I need no sympathy.. Ahem, sorry " <<
		"I'm full, can't add any more contacts..." << std::endl << "Maybe you'd like" <<
		" to erase an existing contact? <yes/no>"
		<< std::endl;
	while (in.compare("yes") != 0 && in.compare("no") != 0) {
		getline(std::cin, in);
		if (in.compare("yes") == 0) {
			Contact::displayPhonebook(phonebook);
			std::cout << std::endl << "Please enter the <INDEX> of the contact you want to erase"
			<< std::endl << " from existence.. I mean, overwrite in the phonebook (or <cancel> "
			<< "to go back to the menu)" << std::endl;
			index = Contact::inputIndex();
			if (index < 0)
				return ;
			std::cout << std::endl << "WOOSH WOOSH!! CONTACT N°" << index << " FLED!" << std::endl << std::endl;
			phonebook[index].fillContact();
		}
		else if (in.compare("no") == 0)
			return;
		else
			std::cout << std::endl << "..wait wut?" << std::endl;
	}
};

void 		Contact::Add(Contact *phonebook) {

	if (Contact::getTotal() < 8)
		phonebook[Contact::getTotal()].fillContact();
	else
		Contact::phonebookFull(phonebook);

}

void 		Contact::displayContact(int i) const {

	std::cout << "     ----- Contact n°" << i + 1 << " -----" << std::endl;
	std::cout << "First name:      " << this->_firstname << std::endl;
	std::cout << "Last name:       " << this->_lastname << std::endl;
	std::cout << "Nickname:        " << this->_nickname << std::endl;
	std::cout << "Login:           " << this->_login << std::endl;
	std::cout << "Adress:          " << this->_postal << std::endl;
	std::cout << "Email:           " << this->_email << std::endl;
	std::cout << "Phone:           " << this->_phone << std::endl;
	std::cout << "Birthday:        " << this->_bday << std::endl;
	std::cout << "Favourite Meal:  " << this->_favMeal << std::endl;
	std::cout << "Underwear Color: " << this->_underwear << std::endl;
	std::cout << "Darkest Secret:  " << this->_secret << std::endl;
	std::cout << "     ----------------------" << std::endl;
};

std::string 	Contact::truncate(std::string str) {

	std::string cpy;

	cpy = str;
	if (cpy.length() > 10) {
		cpy = cpy.substr(0, 9);
		cpy.append(".");
	}
	return cpy;
};

void 		Contact::formatPhonebook(int i) const {

	std::cout << std::setw(10) << i + 1 << '|';
	std::cout << std::setw(10) << this->truncate(this->_firstname) << '|';
	std::cout << std::setw(10) << this->truncate(this->_lastname) << '|';
	std::cout << std::setw(10) << this->truncate(this->_nickname) << std::endl;

};

void Contact::displayPhonebook(Contact *phonebook) {

	std::cout << "----------|----------|----------|----------" << std::endl;
	std::cout << "---INDEX--|-1st NAME-|-LASTNAME-|-NICKNAME-" << std::endl;
	std::cout << "----------|----------|----------|----------" << std::endl;
	for (int i = 0; i < Contact::getTotal(); i++) {
		phonebook[i].formatPhonebook(i);
	}
}

void Contact::Search(Contact *phonebook) {

	if (Contact::getTotal() == 0) {
		std::cout << std::endl << "Well this is embarrassing.. You don't have any"
				<< " contacts yet.." << std::endl;
		return;
	}
	Contact::displayPhonebook(phonebook);
	std::cout << std::endl << "Please enter the <INDEX> of the contact you want to spy"
				<< std::endl << " on.. I mean, get info about (or <cancel> to go back to"
				<< " the menu)" << std::endl;
	int index = Contact::inputIndex();
	if (index < 0)
		return ;
	phonebook[index].displayContact(index);
};

int  Contact::inputIndex(void) {

	std::string tmp;
	int 		index = -1;

	std::getline(std::cin, tmp);
	index = atoi(tmp.c_str()) - 1;
	while (!isdigit(tmp[0]) || tmp.length() != 1 || index < 0 || index >= Contact::getTotal()) {
		if (tmp.compare("cancel") == 0)
			return -1;
		std::cout << std::endl << "As our lord and saviour Mariah Carey once wisely said: I"
				<< std::endl << "don't know her. Please enter a number between 1 and " <<
				Contact::getTotal() << " (or <cancel> to go back to the menu)" << std::endl;
		index = -1;
		std::cin.clear();
		std::getline(std::cin, tmp);
		index = atoi(tmp.c_str()) - 1;
	}
	return index;
};


int 	Contact::getTotal(void) {
	return Contact::_total;
};

int 	Contact::_total = 0;
