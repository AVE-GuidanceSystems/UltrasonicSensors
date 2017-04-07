/*
 * Ultrasonic.h
 *
 *  Created on: Apr 7, 2017
 *      Author: christian
 */
#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_

#include "jetsonGPIO.h"
#include <time.h>
#include <iostream>
#include <unistd.h>

class UltrasoundSensor {
public:
	int distance;
	jetsonGPIO trigger;
	jetsonGPIO echo;
	
	UltrasoundSensor(jetsonGPIO, jetsonGPIO);
	void setTrigger(pinValue);
	void getDistance();
	void printDistance(int);
};
#endif
