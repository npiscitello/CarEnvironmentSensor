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
#include "libraries_and_classes/Sensors.h"
#include "libraries_and_classes/TaskScheduler.h"

	// setup objects
Functions functions;
IO inout;
Sensors sensor;
Scheduler scheduler;
Task periodic_task;

	// storage and callback for the periodic task
char task_storage[2];	// [value, interface]
void periodicCallback() {
	inout.periodicCommand(task_storage[0], task_storage[1]);
}

void setup(){
	periodic_task.setCallback(periodicCallback);
	scheduler.addTask(periodic_task);
}

void loop(){
		// if there's a command available...
	char available = inout.getCommand();
	if(available == 'a') {
		switch(inout.getValue()) {
		case 't':
			sensor.getTemp();
			inout.sendResponse("temperature");
			break;
		case 'c':
			sensor.getCO();
			inout.sendResponse("CO");
			break;
		case 'l':
			sensor.getLat();
			sensor.getLon();
			inout.sendResponse("location");
			break;
		}
			// if a periodic task is called for
		if(inout.getPeriodic()) {
				// store information about the task
			task_storage[0] = inout.getValue();
			task_storage[1] = inout.getInterface();
				// set up the task timing
			periodic_task.setInterval(inout.getInterval());
		}
	} else if(available == 'b') {
		inout.sendResponse("bad parse");
	}
	scheduler.execute();
}
