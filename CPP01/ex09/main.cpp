/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 14:34:17 by esoulard          #+#    #+#             */
/*   Updated: 2020/12/11 15:51:21 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Logger.hpp"

int main(void) {

	Logger log("myLog.log");

	log.log("console", "Dear console diary, HEY SO THIS IS A FIRST ENTRY, i am SUPER BORED right now, it's raining, and cold and i want a burger");
	log.log("file", "Dear log file diary, you know it's been a freaking long year and we've all been so patient. Gotta wait it out, make room for self improvement. That's all there is right? And someday we'll dip our toes in the sea again.. I promise. Pinky swear. Take care");

	return 0;
}