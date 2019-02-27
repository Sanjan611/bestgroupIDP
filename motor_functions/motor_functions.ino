/* 
 * This file is the motor file.
 * Keep all functions used to control the motors and servos.
 */

#include <Wire.h>
#include <Adafruit_MotorShield.h>

Adafruit_MotorShield AFMS = Adafruit_MotorShield(); // create default I2C address motor shield object 
// custom address in brackets, eg Adafruit_MotorShield(0x61)

// set motor ports 
Adafruit_DCMotor *left_motor = AFMS.getMotor(1); // left motor reverse commands
Adafruit_DCMotor *right_motor = AFMS.getMotor(2); // right motor normal commands

// Main two motor controls
void move_forward(front_switch){
  while(front_switch == False){
    
  }
}

void move_backward(){
}

void turn_right(){
  // single wheel drive
}

void turn_left(){
  // single wheel drive
}

// Lift motor
void lift_up(is_max_up){
  while(is_max_up == False){
    // lift goes up until hits top of the shaft
  }
}
void lift_down(is_max_down){
  while(is_max_down == False){
    // lift goes down until hits bottom of the shaft
  }
}

// Sweep servo
