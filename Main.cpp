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

void setup(){}
void loop(){}
