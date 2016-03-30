#include "Sensors.h"
#include <Adafruit_FONA.h>

  // init Fona serial objects
#include <SoftwareSerial.h>
SoftwareSerial fonaSS = SoftwareSerial(2, 3);
SoftwareSerial *fonaSerial = &fonaSS;

  // Fona object
Adafruit_FONA fona = Adafruit_FONA(4);

	// initialize sensors
void Sensors::init(int temp, int co) {
		// set pin for temp sensor
	temp_pin = temp;
	pinMode(temp, INPUT);
		// set pin for CO sensor
	co_pin = co;
	pinMode(co, INPUT);
   // initialize Fona
  Serial.println("FONA initializing...");
//  fonaSerial->begin(4800);
//  if (! fona.begin(*fonaSerial)) {
//    Serial.println(F("Couldn't find FONA"));
//    while(1);
//  }
//  Serial.println(F("GPS Initializing..."));
//  fona.enableGPS(true);
//  Serial.println(F("GPS Enabled"));
}

	// return temperature in �F
float Sensors::getTemp() {
		// convert ADC reading to mV, mV to *C, *C to *F
	return ((((analogRead(temp_pin) * 4.88281) - 500) / 10) * 1.8 + 32);
}

	// return CO concentration in ppm
float Sensors::getCO() {
    // approximately 1ppm per ADC count (analogRead(A1) of 500 means about 500ppm)
  return analogRead(co_pin);
}

	// return latitude in deg
String Sensors::getLoc() {
//  float lat, lon;
    // if this doesn't work, copy the library GPS example
//  boolean gps_success = fona.getGPS(&lat, &lon);
//  if(gps_success) {
//    return ("Your car is here: https://maps.google.com/maps?q=" + String(lat) + "+" + String(lon));
//  } else {
    return "The GPS module could not be read.";
//  }
}

