*
 * Sensors.h
 *
 *  Created on: Mar 18, 2016
 *      Author: piscitellon
 */

#ifndef LIBRARIES_AND_CLASSES_SENSORS_H_
#define LIBRARIES_AND_CLASSES_SENSORS_H_

class Sensors {
public:
	float getTemp();	// return temperature in °F
	float getCO();		// return CO concentration in ppm
	float getLat();		// return latitude in deg
	float getLon();		// return longitude in deg
};

#endif /* LIBRARIES_AND_CLASSES_SENSORS_H_ */
