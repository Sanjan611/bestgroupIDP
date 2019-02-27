/*
 * This file is the motor file.
 * Keep all functions used to control the motors and servos.
 */

Adafruit_MotorShield AFMS = Adafruit_MotorShield(); // create default I2C address motor shield object
// custom address in brackets, eg Adafruit_MotorShield(0x61)

// set motor ports
Adafruit_DCMotor *left_motor = AFMS.getMotor(1); // left motor reverse commands
Adafruit_DCMotor *right_motor = AFMS.getMotor(2); // right motor normal commands

// generic command - move till button pressed, then stop
void move_till_switch(button){
  while(button == false){
    for (i=0; i<255; i++) {
      right_motor->setSpeed(i);
      left_motor->setSpeed(i);
      delay(3);
    }
  }
  else{
    for (i=255; i!=0; i--) {
      right_motor->setSpeed(i);
      left_motor->setSpeed(i);
      delay(1);
    }
  }
}

// Main two motor controls
void move_forward(front_switch){
  right_motor->run(FORWARD);
  left_motor->run(BACKWARD);
  move_till_switch(front_switch);
}

void move_backward(back_switch){
  left_motor->run(FORWARD);
  right_motor->run(BACKWARD);
  move_till_switch(back_switch);
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
