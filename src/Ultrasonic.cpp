/*
 * Ultrasonic.cpp
 *
 *  Created on: Apr 7, 2017
 *      Author: christian
 */
#include "Ultrasonic.h"
using namespace std;

UltrasoundSensor::UltrasoundSensor(jetsonGPIO trig, jetsonGPIO ec){
	//save localy to object
	trigger = trig;
	echo = ec;
	
	//reset pins for use
	gpioUnexport(trig);
	gpioUnexport(echo);
	
	gpioExport(trig);
	gpioExport(echo);
	
	//Set Directions
	gpioSetDirection(trig,1);
	gpioSetDirection(echo, 0);
	
	//Set Default values
	gpioSetValue(trig, 0);
}

void UltrasoundSensor::setTrigger(pinValue state){
	gpioSetValue(trigger, state);
}

void UltrasoundSensor::getDistance(){
	gpioSetValue(trigger, 0);
	usleep(100);
	clock_t start;
	clock_t end;

	gpioSetValue(trigger, 1); //activate Trigger
	//usleep(12);
	start = clock(); 
	//gpioSetValue(trigPin, 0); //deactivate trigger

	unsigned int tempValue = 0;
	//cout << "Grabbing start of pulse..." << endl;
	while (tempValue == 0){
			gpioGetValue(echo, &tempValue); //continue reading if no edge detected
			//cout << "stuck" << endl;
	}
	start = clock(); //calculates current time --start of pulse

	gpioSetValue(trigger, 0); //deactivate trigger

	//cout << "Grabbing end of pulse..." << endl;
	while (tempValue == 1){
			gpioGetValue(echo, &tempValue); //continue reading if no edge detected
	}
	end = clock();//calculate current time --end of pulse
	usleep(10000);	
	double pulseTime = (end - start); 
	
	distance = pulseTime / 58;
}

void UltrasoundSensor::printDistance(int id){
	cout << "Ultrasonic Sensor # "<< id << endl;
	if ((distance >= 300) || (distance <= 20)){
		cout << "Out of Range" << endl;
	}
	else{
		for(int i = 0; i <= distance; i++){
			cout << "-";
		}
		cout << distance << "cm" << endl;
	}
}
