/*
 * Sensors.h
 *
 *  Created on: Mar 18, 2016
 *      Author: piscitellon
 */

#ifndef LIBRARIES_AND_CLASSES_SENSORS_H_
#define LIBRARIES_AND_CLASSES_SENSORS_H_

class Sensors {
public:
	void getTemp();		// return temperature in °F
	void getCO();		// return CO concentration in ppm
	void getLat();		// return latitude in deg
	void getLon();		// return longitude in deg
};

#endif /* LIBRARIES_AND_CLASSES_SENSORS_H_ */
