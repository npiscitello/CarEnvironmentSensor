/*
 * IO.h
 *
 *  Created on: Mar 16, 2016
 *      Author: piscitellon
 */

#ifndef LIBRARIES_AND_CLASSES_IO_H_
#define LIBRARIES_AND_CLASSES_IO_H_

class IO {
	private:
		char value;					// value segment of v-c-p command
		bool periodic;				// command segment of v-c-p command
		unsigned long interval;		// parameter segment of v-c-p command
		bool parseCommand(String);	// parse a natlang or v-c-p command (returns false on a bad parse)
		String checkSerial();		// checks serial input for available command
		String checkGSM();			// checks GSM network for available command
		String checkBT();			// checks Bluetooth interface for available command

	public:
		char getValue();				// returns value segment of v-c-p command
		bool getPeriodic();				// returns command segment of v-c-p command
		unsigned long getInterval();	// returns parameter segment of v-c-p command
		char checkForCommand();			// check for and loads an available command ('a' on available, 'b' on bad parse, 'n' on no command)

};

#endif /* LIBRARIES_AND_CLASSES_IO_H_ */
