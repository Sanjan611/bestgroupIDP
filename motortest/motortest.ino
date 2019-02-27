#include <Wire.h>
#include <Adafruit_MotorShield.h>
Adafruit_DCMotor *left_motor;
Adafruit_DCMotor *right_motor;

void setup() {
  //Serial.begin(9600);           // set up Serial library at 9600 bps

  Adafruit_MotorShield AFMS = Adafruit_MotorShield(); // create default I2C address motor shield object
  // custom address in brackets, eg Adafruit_MotorShield(0x61)

  // set motor ports
  Adafruit_DCMotor *left_motor = AFMS.getMotor(1); // left motor reverse commands
  Adafruit_DCMotor *right_motor = AFMS.getMotor(2); // right motor normal commands

  //AFMS.begin();  // create with the default frequency 1.6KHz
  //AFMS.begin(1000);  // OR with a different frequency, say 1KHz
  
  // Set the speed to start, from 0 (off) to 255 (max speed)
  right_motor->setSpeed(150);
  right_motor->run(FORWARD);
  // turn on motor
  right_motor->run(RELEASE);
  left_motor->setSpeed(150);
  left_motor->run(FORWARD);
  // turn on motor
  left_motor->run(RELEASE);

  
}

void loop() {
  // put your main code here, to run repeatedly:

}
