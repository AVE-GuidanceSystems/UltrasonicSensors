// exampleApp.c

#include <iostream>
#include <string>
#include <unistd.h>
#include <time.h>
#include "jetsonGPIO.h"
#include <stdio.h>
#include "drv2605.h"
#include "Ultrasonic.h"

//Ultrasonic Sensor Object Declaration
UltrasoundSensor Sensor1(gpio187, gpio186); //Sensor(trigger, echo, led)
using namespace std;

int main(int argc, char *argv[]){

    cout << "Testing the GPIO Pins" << endl;
    while(1){
		Sensor1.getDistance();
		cout << Sensor1.distance << endl;
		if ((Sensor1.distance >= 300) || (Sensor1.distance <= 20)){
			//gpioSetValue(LED1, 0); //Turn off led when out of range

		}
		else{
			//gpioSetValue(LED1,1);
		}	
			Sensor1.printDistance(1);
			usleep(30);
	}    
}
