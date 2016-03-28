/*
 * IO.cpp
 *
 *  Created on: Mar 16, 2016
 *      Author: piscitellon
 */

#include "IO.h"

  // initialize
void IO::init() {
  Serial.begin(115200);
}

	// check for and loads an available command ('a' on available, 'b' on bad parse, 'n' on no command)
char IO::getCommand() {
		// interfaces are checked; order determines priority
		// the receiving interface is recorded for the response
	if(getInternal()) {
		// checkInternal() sets interface
	}
	if(getSerial()) {
		interface = 's';
	}
	else if(getGSM()) {
		interface = 'g';
	}
	else if(getBT()) {
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
void IO::sendResponse(String response) {
		// send the message to the appropriate interface (never internal)
	switch(interface) {
	case 's':
    Serial.println(response);
		break;
	case 'g':
		break;
	case 'b':
		break;
	}
}

	// checks internal schedule for periodic tasks
bool IO::getInternal() {
	if(internal_command.length() != 0) {
		command = internal_command;
		interface = internal_interface;
		internal_command = "";
		return true;
	}
	return false;
}

	// checks serial input for available command
bool IO::getSerial() {
	// dump value into IO::command variable
	bool ret = false;
	while(Serial.available() >= 0) {
		command = command + Serial.read();
		ret = true;
	}
	return ret;
}

	// checks GSM network for available command
bool IO::getGSM() {
	// dump value into IO::command variable
	return false;
}

	// checks Bluetooth interface for available command
bool IO::getBT() {
	// dump value into IO::command variable
	return false;
}

	// parse a natlang or v-c-p command (returns false on a bad parse)
bool IO::parseCommand(String command) {
	// parse a natlang or v-c-p command into IO's fields
  // currently only v-c-p commands are supported
  val = command[0];
  if(val != 't' && val != 'c' && val != 'l') {
    return false;
  }
  if(command[2] == 'p') {
    periodic = true;
    // parse interval
  } else {
    periodic = false;
  }
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

	// returns currently stored interface
char IO::getInterface() {
	return interface;
}

	// used by TaskScheduler callbacks; sets the internal command and response interface
void IO::periodicCommand(char incoming_value, char resp_interface) {
	internal_command = String(incoming_value) + String("-n");
	internal_interface = resp_interface;
}
