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
 *  - pinout:
 *    - D2/D3: Fona comms
 *    - A0: temp sensor
 *    - A1: CO sensor (5mV/ppm?) (approx. 1ppm / ADC count - ADC value of 500 means 500ppm)
 */
 
#include "IO.h"
#include "Sensors.h"

	// define pins
const int TEMP_PIN=A0;
const int CO_PIN=A1;

	// setup objects
IO inout;
Sensors sensor;

void setup(){
		// initialize sensors
  inout.init();
	sensor.init(TEMP_PIN, CO_PIN);
}

void loop(){
		// if there's a command available...
  String response;
	char available = inout.getCommand();
	if(available == 'a') {
		switch(inout.getValue()) {
		case 't':
			sensor.getTemp();
      response = "Current temperature: " + String(sensor.getTemp()) + " *F";
			inout.sendResponse(response);
			break;
		case 'c':
			sensor.getCO();
      response = "Current CO concentration: " + String(sensor.getCO()) + " ppm";
			inout.sendResponse(response);
			break;
		case 'l':
			response = sensor.getLoc();
			inout.sendResponse(response);
			break;
		}
			// if a periodic task is called for
		if(inout.getPeriodic()) {
      // periodic task placeholder
		}
	} else if(available == 'b') {
		inout.sendResponse("bad parse");
	}
}
