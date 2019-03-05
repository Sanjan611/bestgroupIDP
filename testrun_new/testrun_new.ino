#include <Wire.h>
#include <Adafruit_MotorShield.h>

Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 


Adafruit_DCMotor *myMotorLeft = AFMS.getMotor(1);
Adafruit_DCMotor *myMotorRight = AFMS.getMotor(2);

const int trigPin = 9; // Trigger Pin of Ultrasonic Sensor
const int echoPin = 10; // Echo Pin of Ultrasonic Sensor
const int hallPin = 5;  // hall effect sensor pin

long duration = 0;
long distance = 0;
float motor_speed = 0;
int distance_limit = 30;
int distance_no_speed = 20;
bool atWall, hall;
long olddist;

int stage = 0;
int nextTurn = 1; // 1 if next turn is right 90, 2 if next turn is right 180, 3 if next turn is left 180
int sweep = 0;


void setup() {
  Serial.begin(9600);         
  Serial.println("Adafruit Motorshield v2 - DC Motor test!");

  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT);
  pinMode(hallPin, INPUT);

  AFMS.begin();  // create with the default frequency 1.6KHz

  myMotorLeft->run(RELEASE);
  myMotorRight->run(RELEASE);
  olddist = get_distance();
  motor_speed = 255;
  atWall = false;
}

void loop() {

  distance = get_distance(); 
  /*
   *  
  if(olddist < distance) {
    Serial.println("getting further");
    delay(200);
  }
  else if(olddist > distance) {
    Serial.println("getting closer");
    delay(200);  
  }
  else{
    Serial.println("all chill");
    delay(200);
  }*/

  switch(stage){
    case 0: // moves forward till wall
          Serial.println("case 0");
          if(sweep == 6){
            Serial.println("sweep 6");
            distance_limit = 130;
            distance_no_speed = 120;
            nextTurn = 4;
          }
          else if(sweep == 7) nextTurn = 5;
          atWall = moveToWall(distance_limit, distance_no_speed);
          if(atWall == true){
            stage = nextTurn;
          }
          break;
    case 1: // turn right 90 degrees
          Serial.println("turning 90 right");
          //Serial.println("you made it into case 1 well done");
          motor_speed = 100;
          turnRight(myMotorLeft, motor_speed, myMotorRight, 0, 4500);
          stage = 0;
          nextTurn += 1;
          atWall = false;
          sweep = 1;
          distance_limit = 40;
          distance_no_speed = 25;
          break;

    case 2: // turn right 180 degrees
          Serial.println("turning 180 right");
          motor_speed = 100;
          turnRight(myMotorLeft, motor_speed, myMotorRight, 0, 9050);
          stage = 0;
          nextTurn += 1;
          atWall = false;
          sweep += 1;
          break;
    case 3: // turn left 180 degrees
          Serial.println("turning 180 left");
          motor_speed = 100;
          turnLeft(myMotorLeft, 0, myMotorRight, motor_speed, 9050);
          stage = 0;
          nextTurn -= 1;
          atWall = false;
          sweep += 1;
          break;
    case 4: // turn left 90 degrees
          Serial.println("turning 90 left");
          motor_speed = 100;
          turnLeft(myMotorLeft, 0, myMotorRight, motor_speed, 4500);
          stage = 0;
          sweep = 7;
          distance_limit = 20;
          distance_no_speed = 7;
          break;

    case 5:
          stopMotor(myMotorLeft, myMotorRight, 20);

  }
  olddist = distance;
}
