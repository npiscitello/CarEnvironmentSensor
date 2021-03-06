#include "Sensors.h"
#include <Adafruit_FONA.h>

  // init Fona serial objects
#include <SoftwareSerial.h>
SoftwareSerial fonaSS = SoftwareSerial(3, 2);
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
  fonaSerial->begin(4800);
  if (! fona.begin(*fonaSerial)) {
    Serial.println(F("Couldn't find FONA"));
  } else {
    Serial.println(F("GPS Initializing..."));
    fona.enableGPS(true);
    Serial.println(F("GPS Enabled"));
  }
}

	// return temperature in *F
float Sensors::getTemp() {
		// convert ADC reading to mV, mV to *C, *C to *F
	return ((((analogRead(temp_pin) * 4.88281) - 500) / 10) * 1.8 + 32);
}

	// return CO concentration in ppm
float Sensors::getCO() {
    // approximately 1ppm per ADC count (analogRead(A1) of 500 means about 500ppm)
  return 0.1 * analogRead(co_pin);
}

	// return latitude in deg
String Sensors::getLoc() {
  float lat, lon;
    // if this doesn't work, copy the library GPS example
  boolean gps_success = fona.getGPS(&lat, &lon);
  if(gps_success) {
    Serial.print(F("https://maps.google.com/maps?q=")); printFloat(lat, 15);
    Serial.print(F("+")); printFloat(lon, 15); Serial.println();
    return ("  <- Your car is here");
  } else {
    return "The GPS module could not find a fix.";
  }
}

void printFloat(float value, int places) {
  // this is used to cast digits 
  int digit;
  float tens = 0.1;
  int tenscount = 0;
  int i;
  float tempfloat = value;

    // make sure we round properly. this could use pow from <math.h>, but doesn't seem worth the import
  // if this rounding step isn't here, the value  54.321 prints as 54.3209

  // calculate rounding term d:   0.5/pow(10,places)  
  float d = 0.5;
  if (value < 0)
    d *= -1.0;
  // divide by ten for each decimal place
  for (i = 0; i < places; i++)
    d/= 10.0;    
  // this small addition, combined with truncation will round our values properly 
  tempfloat +=  d;

  // first get value tens to be the large power of ten less than value
  // tenscount isn't necessary but it would be useful if you wanted to know after this how many chars the number will take

  if (value < 0)
    tempfloat *= -1.0;
  while ((tens * 10.0) <= tempfloat) {
    tens *= 10.0;
    tenscount += 1;
  }


  // write out the negative if needed
  if (value < 0)
    Serial.print('-');

  if (tenscount == 0)
    Serial.print(0, DEC);

  for (i=0; i< tenscount; i++) {
    digit = (int) (tempfloat/tens);
    Serial.print(digit, DEC);
    tempfloat = tempfloat - ((float)digit * tens);
    tens /= 10.0;
  }

  // if no places after decimal, stop now and return
  if (places <= 0)
    return;

  // otherwise, write the point and continue on
  Serial.print('.');  

  // now write out each decimal place by shifting digits one by one into the ones place and writing the truncated value
  for (i = 0; i < places; i++) {
    tempfloat *= 10.0; 
    digit = (int) tempfloat;
    Serial.print(digit,DEC);  
    // once written, subtract off that digit
    tempfloat = tempfloat - (float) digit; 
  }
}

