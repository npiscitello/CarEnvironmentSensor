/*
 * IO.cpp
 *
 *  Created on: Mar 16, 2016
 *      Author: piscitellon
 */

#include "IO.h"

	// check for and loads an available command ('a' on available, 'b' on bad parse, 'n' on no command)
char IO::checkForCommand() {
	String command;
	// check each interface in priority order
	// if nothing has data, return 'n'
	if(!parseCommand(command)) {
		return 'b';
	}
	return 'a';
}

	// parse a natlang or v-c-p command (returns false on a bad parse)
bool IO::parseCommand(String command) {
	// parse a natlang or v-c-p command into IO's fields
	return true;
}

	// returns value segment of v-c-p command
char IO::getValue() {
	return '\0';
}

	// returns command segment of v-c-p command
bool IO::getPeriodic() {
	return false;
}

	// returns parameter segment of v-c-p command
unsigned long IO::getInterval() {
	return 0;
}
