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
int distance_no_speed = 15;
bool atWall;

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

  distance = get_distance(); 

  switch(stage){
    case 0: // moves forward till wall
            atWall = moveToWall(distance_limit, distance_no_speed);
            if(atWall == true){
              Serial.println("AT WALL YAY");
              stage = 1;
            }
            
            break;

    case 1: // turn right, move straight till wall
          Serial.println("you made it into case 1 well done");
          motor_speed = 100;
          turnRight(myMotorLeft, motor_speed, myMotorRight, 0, 4400);
          stage = 0;
          break;

    case 2: // Take 180 turn, move straight till wall
    // this happens for 5 times?
    break;

  }

  
}
