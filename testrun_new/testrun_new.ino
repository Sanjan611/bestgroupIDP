#include <Wire.h>
#include <Adafruit_MotorShield.h>

Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 


Adafruit_DCMotor *myMotorLeft = AFMS.getMotor(1);
Adafruit_DCMotor *myMotorRight = AFMS.getMotor(2);

const int trigPin = 9; // Trigger Pin of Ultrasonic Sensor
const int echoPin = 10; // Echo Pin of Ultrasonic Sensor
long duration = 0;
long distance = 0;
float motor_speed = 0;
int distance_limit = 30;
int distance_no_speed = 10;

int stage = 0;

void setup() {
  Serial.begin(9600);         
  Serial.println("Adafruit Motorshield v2 - DC Motor test!");

  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT);

  AFMS.begin();  // create with the default frequency 1.6KHz

  myMotorLeft->run(RELEASE);
  myMotorRight->run(RELEASE);

  

}

void loop() {

  switch(stage){
    case 0: // moves forward till wall
            moveToWall(distance_limit, distance_no_speed);
            break;

    case 1: // turn right, move straight till wall
    break;

    case 2: // Take 180 turn, move straight till wall
    // this happens for 5 times?
    break;

  }

  stage = 0;

  
}
