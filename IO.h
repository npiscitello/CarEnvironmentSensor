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
		String internal_command;	// command holder for periodic tasks
		char internal_interface;	// stores what interface a periodic task is responding to
		char interface;				// the source of the current command
		char val;					  // value segment of v-c-p command
		bool periodic;				// command segment of v-c-p command
		unsigned long interval;		// parameter segment of v-c-p command
		bool parseCommand(String);	// parse a natlang or v-c-p command (returns false on a bad parse)
		bool getInternal();			// checks internal schedule for periodic tasks
		bool getSerial();			// checks serial input for available command
		bool getGSM();				// checks GSM network for available command
		bool getBT();				// checks Bluetooth interface for available command

	public:
    void init();              // initializes values and functions
		char getValue();					// returns value segment of v-c-p command
		bool getPeriodic();					// returns command segment of v-c-p command
		unsigned long getInterval();		// returns parameter segment of v-c-p command
		char getInterface();				// returns currently stored interface
		char getCommand();					// check for and loads an available command ('a' on available, 'b' on bad parse, 'n' on no command)
		void sendResponse(String);			// send a response to the last receiving interface
		void periodicCommand(char, char);	// used by TaskScheduler callbacks; sets the internal command and response interface
};

#endif /* LIBRARIES_AND_CLASSES_IO_H_ */
