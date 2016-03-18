/* Nick Piscitello, 2016 for WIT ENGR1500-35
 *
 * Pseudocode:
 * 	- ask parser if there are any new commands waiting to be executed (IO.checkForCommand())
 * 		- parser polls all input methods for new data, converts to v-c-p format if natlang
 *		- I/O module provides get... methods for value, command, and parameter
 *	- execute if loops or case statement to interface with the appropriate module
 *		- p command, set timer then execute appropriate functions object method
 *		- n command, just execute appropriate functions object
 *	- timers:
 *		- hardware watchdog for freeze-ups
 *		- board reset every so often (weeks?)
 *		- software timer for periodic functions
 *
 */

#include <Arduino.h>
#include "libraries_and_classes/Functions.h"
#include "libraries_and_classes/IO.h"
#include "libraries_and_classes/TaskScheduler.h"

	// setup objects
Functions functions;
IO inout;

void setup(){}

void loop(){
		// if there's a command available...
	char available = inout.checkForCommand();
	if(available == 'a') {
		switch(inout.getValue()) {
		case 't':
			break;
		case 'c':
			break;
		case 'l':
			break;
		}
			// if a periodic task is called for
		if(inout.getPeriodic()) {
			// set up periodic action based on inout.getInterval
		}
	} else if(available == 'b') {
		inout.sendResponse(false);
	}
}
