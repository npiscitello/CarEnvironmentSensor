#include "Sensors.h"

	// initialize sensors
void Sensors::init(int temp, int co) {
		// set pin for temp sensor
	temp_pin = temp;
	pinMode(temp, INPUT);
		// set pin for CO sensor
	co_pin = co;
	pinMode(co, INPUT);
		// setup GPS sensor
}

	// return temperature in �F
float Sensors::getTemp() {
		// convert ADC reading to mV, mV to *C, *C to *F
	return ((((analogRead(temp_pin) * 4.88281) - 500) / 10) * 1.8 + 32);
}

	// return CO concentration in ppm
float Sensors::getCO() {
  return 0;
}

	// return latitude in deg
float Sensors::getLat() {
  return 0;
}

	// return longitude in deg
float Sensors::getLon() {
  return 0;
}
