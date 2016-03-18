/*
 * IO.h
 *
 *  Created on: Mar 16, 2016
 *      Author: piscitellon
 */

#include <Arduino.h>

#ifndef LIBRARIES_AND_CLASSES_IO_H_
#define LIBRARIES_AND_CLASSES_IO_H_

class IO {
	private:
		String command;				// raw command from interface
		char interface;				// the source of the current command
		char value;					// value segment of v-c-p command
		bool periodic;				// command segment of v-c-p command
		unsigned long interval;		// parameter segment of v-c-p command
		bool parseCommand(String);	// parse a natlang or v-c-p command (returns false on a bad parse)
		bool checkSerial();			// checks serial input for available command
		bool checkGSM();			// checks GSM network for available command
		bool checkBT();				// checks Bluetooth interface for available command

	public:
		char getValue();				// returns value segment of v-c-p command
		bool getPeriodic();				// returns command segment of v-c-p command
		unsigned long getInterval();	// returns parameter segment of v-c-p command
		char checkForCommand();			// check for and loads an available command ('a' on available, 'b' on bad parse, 'n' on no command)
		void sendResponse(bool);		// send a response to the last receiving interface

};

#endif /* LIBRARIES_AND_CLASSES_IO_H_ */
