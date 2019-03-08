#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include<Servo.h> 

Servo servoFlap;
Servo servoArm;

Adafruit_MotorShield AFMS = Adafruit_MotorShield();


Adafruit_DCMotor *myMotorLeft = AFMS.getMotor(1);
Adafruit_DCMotor *myMotorRight = AFMS.getMotor(2);
Adafruit_DCMotor *myMotorLift = AFMS.getMotor(3);



// function and variable definitions
bool moveToWall(int distance_limit, int distance_no_speed);
const int trigPinFront = 2; // Trigger Pin of Ultrasonic Sensor
const int echoPinFront = 3; // Echo Pin of Ultrasonic Sensor
const int trigPinSide = 6;
const int echoPinSide = 7;
int trigPin, echoPin;
const int photoPin = 4; // Phototransistor Pin - high for block, low for no block
const int hallPin = 5;  // hall effect sensor pin
const int microPin = 4;
long duration = 0;
float distance = 0;
float motor_speed = 0;
int distance_limit = 30;
int distance_no_speed = 20;
bool atWall, hall;
long olddist;
int stage = 0;
int nextTurn = 1; // 1 if next turn is right 90, 2 if next turn is right 180, 3 if next turn is left 180
int sweep = 0;
int autoCounter = 0, liftCounter = 0;
float sideDist, sideDistOld, diff;
float kp = 20;
bool rwheel;
int pos;



void setup() {
  Serial.begin(9600);
  Serial.println("Hello! I'm Henry the Robot.");

  // ultrasound pin setup - trigger output, echo input
  pinMode(trigPinFront, OUTPUT); 
  pinMode(echoPinFront, INPUT);
  pinMode(trigPinSide, OUTPUT); 
  pinMode(echoPinSide, INPUT);
  pinMode(microPin, INPUT);

  // magnetic pin setup
  pinMode(hallPin, INPUT);

  // initialise motor operation
  AFMS.begin();  // create with the default frequency 1.6KHz

  // initialise right and left motors, set initial speed and readings
  myMotorLeft->run(RELEASE);
  myMotorRight->run(RELEASE);
  myMotorLift->run(RELEASE);
  
  motor_speed = 255;
  atWall = false;
  sideDist = get_distance(2);
  
  // setting up the servo motors
  servoFlap.attach(10); // the pin!
  servoArm.attach(9); // the pin! 

  //servoFlap.write(180);
  //delay(1000);
  //servoFlap.write(0);
  //delay(1000);

  //myservo.attach(10);

  // servoFlap.attach(...); // the pin!
  // servoArm.attach(...); // the pin!
  /*
  moveForward(myMotorLeft, 255, myMotorRight, 255, 4500);
  Serial.println("Lift going up!");
  delay(3000);
  moveBackwards(myMotorLeft, 255, myMotorRight, 255, 7000);
  Serial.println("Lift going down!");
  delay(3000);
  */

  stage = 12;
          
}



void loop() {


  // counter for path auto-correction - checks every 20 loops 
  autoCounter += 1;
  if(autoCounter > 20) {
    autoCounter = 0;
  }

  // compares previous and current distance from wall, adjusts path proportionally to difference
  if(autoCounter == 0){
    sideDistOld = sideDist;
    sideDist = get_distance(2);
    Serial.println(sideDist);
    diff = sideDist - sideDistOld;
    if(sideDistOld > sideDist){
      rwheel = true;
      diff = -diff;
    }
    else if(sideDistOld < sideDist){
      rwheel = false;
    }
    else{
      diff = 0;
    }
    
    // differences above 7cm discarded as anomalous
    // differences while turning set to 0
    if(diff > 7 || stage != 0) diff = 0;
  }
  
  distance = get_distance(1);

  switch(stage){
    case 0: // moves forward till wall

          // drop off shelf causes some error in ultrasound behaviour - readings disregarded when US pointing at shelf
          if(distance > 100 && distance < 140 && nextTurn == 3 && sweep != 1 && sweep < 6) diff = 0; 
          
          if(sweep == 6){ // if in the last portion of journey, go halfway and turn towards shelf
            distance_limit = 130;
            distance_no_speed = 120;
            nextTurn = 4;
          }
          else if(sweep == 7) nextTurn = 5; // if facing to shelf, go forward and stop completely 
          else if(sweep == 8){ 
            nextTurn = 7;
            distance_limit = 35;
            distance_no_speed = 25;
          }

          //checkForBlock(); // incomplete function changing behaviour when blocks detected


          // move forward with course correction until wall reached
          atWall = moveToWall(distance_limit, distance_no_speed);

          // when wall reached, move onto next stage
          if(atWall == true){ // turns when gets close to wall
            stage = nextTurn;
          }

          break;
    case 1: // turn right 90 degrees
          Serial.println("turning 90 right");
          //Serial.println("you made it into case 1 well done");
          motor_speed = 100;
          turnRight(myMotorLeft, motor_speed, myMotorRight, 0, 4550);
          stage = 0;
          nextTurn += 1;
          sweep = 1;
          break;

    case 2: // turn right 180 degrees
          Serial.println("turning 180 right");
          motor_speed = 100;
          turnRight(myMotorLeft, motor_speed, myMotorRight, 0, 9300);
          stage = 0;
          nextTurn += 1;
          sweep += 1;
          break;
    case 3: // turn left 180 degrees
          Serial.println("turning 180 left");
          motor_speed = 100;
          turnLeft(myMotorLeft, 0, myMotorRight, motor_speed, 9300);
          stage = 0;
          nextTurn -= 1;
          sweep += 1;
          break;
    case 4: // turn left 90 degrees
          Serial.println("turning 90 left");
          motor_speed = 100;
          turnLeft(myMotorLeft, 0, myMotorRight, motor_speed, 4500);
          stage = 0;
          sweep = 7;
          distance_limit = 20;
          distance_no_speed = 9;
          break;

    case 5: // at loading place
          stopRLMotors(5000, myMotorRight, myMotorLeft);
          stage = 6;
          break;
          
    case 6: // parking - very ugly rough code but it works
          motor_speed = 255;
          moveBackwards(myMotorLeft, motor_speed, myMotorRight, motor_speed, 1000);
          motor_speed = 100;
          turnLeft(myMotorLeft, 0, myMotorRight, motor_speed, 4550);
          stage = 0;
          sweep = 8;
          break;
    case 7: // parking
          turnRight(myMotorLeft, motor_speed, myMotorRight, 0, 4550);
          stage = 8;
          break;
    case 8: // parking
          stopRLMotors(5000, myMotorRight, myMotorLeft);
          break;

    case 10:  // case just for testing

          openFlap(servoFlap, 40, 120);
        
        
          delay(5000);

          //liftGoingUp(myMotorLift, 255, 5000);
          /*
          moveForward(myMotorLeft, 255, myMotorRight, 255, 5500);
          Serial.println("Lift going up!");
          delay(3000);
          */

          closeFlap(servoFlap, 120, 40);
      
        
          delay(5000);

          //liftGoingDown(myMotorLift, 255, 5000);
          /*
          moveBackwards(myMotorLeft, 255, myMotorRight, 255, 10000);
          Serial.println("Lift going down!");
          delay(3000);
          */
          
          break;

     case 11:
          while(1){
            moveForward(myMotorRight, 200, myMotorLeft, 200, 5000);
          }
          break;

     case 12:
            // trying an integrated case of lift down -> flap close -> lift up -> flap open -> sweep arm
            Serial.println("Starting mechanism ...");
            delay(2000);
            bringArmToNeutral(servoArm, 0);
            Serial.println("Brought arm to neutral");
            delay(2000);
            liftGoingUp(myMotorLift, 255, 7000);
            Serial.println("Lift went up");
            delay(2000);
            openFlap(servoFlap, 40, 120);
            Serial.println("Flap opened");
            delay(2000);
            liftGoingDown(myMotorLift, 255, 5000);
            Serial.println("Lift went down");
            delay(2000);
            closeFlap(servoFlap, 120, 40);
            Serial.println("Flap closed");
            delay(2000);
            liftGoingUp(myMotorLift, 255, 7000);
            Serial.println("Lift went up");
            delay(2000);
            openFlap(servoFlap, 40, 120);
            Serial.println("Flap opened");
            delay(2000);
            sweepTheArm(servoArm, 0, 120, 5);
            Serial.println("Sweep arm swept");
            stage = 100;
            break;

     case 13:
            Serial.println("Inside case 13!");
            //liftGoingUp(myMotorLift, 255, 9000);
            sweepTheArm(servoArm, 0, 120, 5);
            delay(3000);
     case 100:
            break;

  }
}
