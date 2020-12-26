/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 13:42:11 by esoulard          #+#    #+#             */
/*   Updated: 2020/12/11 14:39:10 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"

void Human::meleeAttack(std::string const & target) {

	std::cout << "Human pokes " << target << " with chopsticks" << std::endl;
};

void Human::rangedAttack(std::string const & target) {

	std::cout << "Human exhales their terrible garlic breath in " << target << "'s direction" << std::endl;
};

void Human::intimidatingShout(std::string const & target) {

	std::cout << "Human shrieks: '" << target << ", THIS SALAD IS SO BADLY DRESSED IT WOULD EVEN SHOCK LADY GAGA" << std::endl;
};

void Human::action(std::string const & action_name, std::string const & target) {

	actionPtrType actionPtr[] = {&Human::meleeAttack, &Human::rangedAttack, &Human::intimidatingShout};
	std::string actionStrings[] = {"meleeAttack", "rangedAttack", "intimidatingShout"};

	for (int i = 0; i < 3; i++) {
		if (action_name == actionStrings[i]) {
			(this->*actionPtr[i])(target);
			break;
		}
	}
};