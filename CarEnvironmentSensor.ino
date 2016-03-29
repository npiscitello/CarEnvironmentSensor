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
#include "Functions.h"
#include "IO.h"
#include "Sensors.h"
#include "TaskScheduler.h"

	// define pins
const int TEMP_PIN=A0;
const int CO_PIN=A1;

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
		// setup periodic task
	periodic_task.setCallback(periodicCallback);
	scheduler.addTask(periodic_task);
		// initialize sensors
	sensor.init(TEMP_PIN, CO_PIN);
  inout.init();
}

void loop(){
		// if there's a command available...
  String response;
	char available = inout.getCommand();
	if(available == 'a') {
		switch(inout.getValue()) {
		case 't':
			sensor.getTemp();
      response = "Current temperature: " + String(sensor.getTemp());
			inout.sendResponse(response);
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
