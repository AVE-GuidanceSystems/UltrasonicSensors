//@ Damon Chan 2017
// Echo distancing using ultrasonic sensors

#define trig1Pin 1
#define echo1Pin 2
#define echo2Pin 3
#define echo3Pin 4
#define echo4Pin 5
#define echo5Pin 6
#define echo6Pin 7
#define ledk 8
#define ledw 9
#define ledb 10
#define ledr 11
#define ledg 12
#define ledo 13

int distance1 = 0;
int distance2 = 0;
int distance3 = 0;
int distance4 = 0;
int distance5 = 0;
int distance6 = 0;

void setup() {
  Serial.begin (115200);
  pinMode(trig1Pin, OUTPUT);
  pinMode(echo1Pin, INPUT);
  pinMode(echo2Pin, INPUT);
  pinMode(echo3Pin, INPUT);
  pinMode(echo4Pin, INPUT);
  pinMode(echo5Pin, INPUT);
  pinMode(echo6Pin, INPUT);
  pinMode(ledk, OUTPUT);
  pinMode(ledw, OUTPUT);
  pinMode(ledb, OUTPUT);
  pinMode(ledr, OUTPUT);
  pinMode(ledg, OUTPUT);
  pinMode(ledo, OUTPUT);
}

void loop() {
  distance1 = getDistance(trig1Pin, echo1Pin);
  if (distance1 >= 300 || distance1 <= 20) // This is where the LED On/Off happens
    digitalWrite(ledk,LOW); // When the condition is met, the LED should turn on
  else
    digitalWrite(ledk,HIGH);
  printDistance(1, distance1);
  delay(10);
  
  distance2 = getDistance(trig1Pin, echo2Pin);
  if (distance2 >= 300 || distance2 <= 20) // This is where the LED On/Off happens
    digitalWrite(ledw,LOW); // When the condition is met, the LED should turn on
  else
    digitalWrite(ledw,HIGH);
  printDistance(2, distance2);
  delay(10);
 
  distance3 = getDistance(trig1Pin, echo3Pin);
  if (distance3 >= 300 || distance3 <= 20) // This is where the LED On/Off happens
    digitalWrite(ledb,LOW); // When the condition is met, the LED should turn on
  else
    digitalWrite(ledb,HIGH);
  printDistance(3, distance3);
  delay(10);
 
  distance4 = getDistance(trig1Pin, echo4Pin);
  if (distance4 >= 300 || distance4 <= 20) // This is where the LED On/Off happens
    digitalWrite(ledr,LOW); // When the condition is met, the LED should turn on
  else
    digitalWrite(ledr,HIGH);
  printDistance(4, distance4);
  delay(10);
 
  distance5 = getDistance(trig1Pin, echo5Pin);
  if (distance5 >= 300 || distance5 <= 20) // This is where the LED On/Off happens
    digitalWrite(ledg,LOW); // When the condition is met, the LED should turn on
  else
    digitalWrite(ledg,HIGH);
  printDistance(5, distance5);
  delay(10);
 
  distance6 = getDistance(trig1Pin, echo6Pin);
  if (distance6 >= 300 || distance6 <= 20) // This is where the LED On/Off happens
    digitalWrite(ledo,LOW); // When the condition is met, the LED should turn on
  else
    digitalWrite(ledo,HIGH);
  printDistance(6, distance6);
  delay(10);
 }

int getDistance (int trigPin, int echoPin) {
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trigPin, LOW);  
  unsigned long pulseTime = pulseIn(echoPin, HIGH);
  int distance = pulseTime / 58;
  return distance;
}
 
void printDistance(int id, int dist) {
  Serial.print(id);
  if (dist >= 300 || dist <= 20) {
    Serial.println(" Out of range");
  }
   else
    for (int i = 0; i <= dist; i++) {
      Serial.print("-");
    }
    Serial.print(dist, DEC);
    Serial.println(" cm");
} 
