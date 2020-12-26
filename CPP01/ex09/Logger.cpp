/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Logger.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 14:33:29 by esoulard          #+#    #+#             */
/*   Updated: 2020/12/11 15:38:11 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Logger.hpp"
#include <iomanip>
#include <fstream>

Logger::Logger(std::string FileName): _logFileName(FileName) {

	std::cout << "Log initialized! Ready to log to console or " << _logFileName
	<< std::endl;
};

Logger::~Logger(void) {

	std::cout << "Log over" << std::endl;
};


void 		Logger::logToConsole(std::string const &str) {

	std::cout << str << std::endl;
};

void 		Logger::logToFile(std::string const &str) {
	
	std::ofstream ofs(this->_logFileName);
	ofs << str << std::endl;
	ofs.close();
};
	
std::string	Logger::makeLogEntry(std::string const str) {

	std::stringstream ss;
	std::string formattedLog;

	std::time_t time_now = std::time(nullptr);
	ss << std::put_time(std::localtime(&time_now), "[%Y%m%d_%OH%OM%OS] ");
	ss >> formattedLog;
	formattedLog += str;

	return formattedLog;
};


void 		Logger::log(std::string const &dest, std::string const &message) {

	std::string formattedLog = makeLogEntry(message);

	for (int i = 0; i < 2; i++) {
		if (_logFunctionNames[i] == dest) {
			(this->*_logPtr[i])(formattedLog);
			break;
		}
	}
};


std::string 		Logger::_logFunctionNames[] = {"console", "file"};

Logger::logPtrType	Logger::_logPtr[] = {&Logger::logToConsole, &Logger::logToFile};