/*
 * IO.cpp
 *
 *  Created on: Mar 16, 2016
 *      Author: piscitellon
 */

#include "IO.h"

char IO::checkForCommand() {
	String command;
	// check each interface in priority order
	// if nothing has data, return 'n'
	if(!parseCommand(command)) {
		return 'b';
	}
	return 'a';
}
