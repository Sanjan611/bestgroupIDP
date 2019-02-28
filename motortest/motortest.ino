#include <Wire.h>
#include <Adafruit_MotorShield.h>
Adafruit_MotorShield AFMS = Adafruit_MotorShield();
Adafruit_DCMotor *leftmotor = AFMS.getMotor(1); // left motor reverse commands
Adafruit_DCMotor *rightmotor = AFMS.getMotor(2); // right motor normal commands
const int trigPin = 9;
const int echoPin = 10;
long duration;
float distance;
bool keepgoing;
uint8_t i;


void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600);           // set up Serial library at 9600 bps

   // create default I2C address motor shield object
  // custom address in brackets, eg Adafruit_MotorShield(0x61)

  //AFMS.begin();  // create with the default frequency 1.6KHz
  //AFMS.begin(1000);  // OR with a different frequency, say 1KHz
  
  // Set the speed to start, from 0 (off) to 255 (max speed)
  //right_motor->setSpeed(150);
  //right_motor->run(FORWARD);
  // turn on motor
  rightmotor->run(RELEASE);
  //left_motor->setSpeed(150);
  //left_motor->run(FORWARD);
  // turn on motor
  leftmotor->run(RELEASE);
}

void loop() {
  // if right distance to wall is decreasing, speed up right motor
  // if -----------------------is increasing, speed up left motor
  // if front distance to wall is x, stop
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  
  // Calculating the distance
  distance= duration*0.034/2;

  

  if(distance>10){
    Serial.println("INSIDE THE IF!!");
    rightmotor->setSpeed(0);
    leftmotor->setSpeed(0);
    rightmotor->run(FORWARD);
    leftmotor->run(BACKWARD);
    delay(1000);
    
  }
  else{
    Serial.println("INSIDE THE ELSE");
    rightmotor->setSpeed(100);
    leftmotor->setSpeed(100);
    rightmotor->run(BACKWARD);
    leftmotor->run(FORWARD);
    
    delay(1000);
  }

  //right_motor->run(RELEASE);
  //left_motor->run(RELEASE);

  
  
  // Prints the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.println(distance);

}
