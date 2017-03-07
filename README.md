# Ultrasonic-Sensor-Test
Sample code found in the arduino example library

# Eventual Use
To test ultrasonic sensor array for detection speed, reliability of discovered obstruction and as a preliminary identifier of obstacles user may encounter.

# Theory
Can be based on the following link
http://arduino-info.wikispaces.com/Ultrasonic+Distance+Sensor

Basic Idea:
"The speed of sound is approximately 341 meters (1100 feet) per second in air...Distance = Time x Speed of Sound divided by 2"

Therefor, the microcontroller is using the ultrasonic sensor to measure the time of flight (meaning the distance from source to object and back to source, thus the divide by 2)
