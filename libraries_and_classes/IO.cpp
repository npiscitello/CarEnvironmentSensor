/*
 * IO.cpp
 *
 *  Created on: Mar 16, 2016
 *      Author: piscitellon
 */

#include "IO.h"

	// check for and loads an available command ('a' on available, 'b' on bad parse, 'n' on no command)
char IO::checkForCommand() {
		// interfaces are checked; order determines priority
		// the recieving interface is recorded for the response
	if(checkSerial()) {
		interface = 's';
	}
	else if(checkGSM()) {
		interface = 'g';
	}
	else if(checkBT()) {
		interface = 'b';
	}
		// if nothing has data, return 'n'
	else {
		return 'n';
	}
		// parse the command; if the parser can't understand, return 'b'
	if(!parseCommand(command)) {
		return 'b';
	}
	return 'a';
}

	// send a response to the last receiving interface
void IO::sendResponse(bool parsed) {
	if(parsed) {
			// build the message based on the request
		switch(value) {
		case 't':
			break;
		case 'c':
			break;
		case 'l':
			break;
		}
			// send the message to the appropriate interface
		switch(interface) {
		case 's':
			break;
		case 'g':
			break;
		case 'b':
			break;
		}
	} else {
		// send a bad parse message
	}
}

	// checks serial input for available command
bool IO::checkSerial() {
	// dump value into IO::command variable
	return false;
}

	// checks GSM network for available command
bool IO::checkGSM() {
	// dump value into IO::command variable
	return false;
}

	// checks Bluetooth interface for available command
bool IO::checkBT() {
	// dump value into IO::command variable
	return false;
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
