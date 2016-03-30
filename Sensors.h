#ifndef LIBRARIES_AND_CLASSES_SENSORS_H_
#define LIBRARIES_AND_CLASSES_SENSORS_H_

class Sensors {
private:
	int temp_pin;	// stores pin number for temp sensor
	int co_pin;	// stores pin number for co sensor
public:
	void init(int,int);	// initialize sensors
	float getTemp();	// return temperature in �F
	float getCO();		// return CO concentration in ppm
	String getLoc();   // return string for printing
};

#endif /* LIBRARIES_AND_CLASSES_SENSORS_H_ */
