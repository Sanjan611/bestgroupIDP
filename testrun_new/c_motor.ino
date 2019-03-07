void moveForward(Adafruit_DCMotor *motor1, long motor_speed_1, Adafruit_DCMotor *motor2, long motor_speed_2, long dur){

  motor1->setSpeed(motor_speed_1);
  motor2->setSpeed(motor_speed_2);

  motor1->run(BACKWARD);
  motor2->run(FORWARD);

  delay(dur);
}

void moveBackwards(Adafruit_DCMotor *motor1, long motor_speed_1, Adafruit_DCMotor *motor2, long motor_speed_2, long dur){

  motor1->setSpeed(motor_speed_1);
  motor2->setSpeed(motor_speed_2);

  motor1->run(FORWARD);
  motor2->run(BACKWARD);

  delay(dur);

  for(int i = 100; i >= 0; i--){
    motor1->setSpeed(i);
    motor2->setSpeed(i);
    delay(10);
  }
}

void turnRight(Adafruit_DCMotor *motor1, long motor_speed_1, Adafruit_DCMotor *motor2, long motor_speed_2, long dur){

  motor1->setSpeed(motor_speed_1);
  motor2->setSpeed(motor_speed_2);

  motor1->run(BACKWARD);
  motor2->run(BACKWARD);

  delay(dur);

  motor1->run(RELEASE);
  motor2->run(RELEASE);


  
}

void turnLeft(Adafruit_DCMotor *motor1, long motor_speed_1, Adafruit_DCMotor *motor2, long motor_speed_2, long dur){

  motor1->setSpeed(motor_speed_1);
  motor2->setSpeed(motor_speed_2);

  motor2->run(FORWARD);

  delay(dur);

  motor1->run(RELEASE);
  motor2->run(RELEASE);
}

void stopMotor(Adafruit_DCMotor *motor1, Adafruit_DCMotor *motor2, long dur){
  motor1->setSpeed(0);
  motor2->setSpeed(0);

  motor1->run(RELEASE);
  motor2->run(RELEASE);

  delay(dur);
}

bool isStuck(){
  
}

void closeFlap(Servo &servo, int start_degree, int end_degree){
  //servoFlap.write(0);
  //delay(2000);

  for (pos = start_degree; pos >= end_degree; pos -= 1) { // goes from 180 degrees to 0 degrees
     servo.write(pos);              // tell servo to go to position in variable 'pos'
     delay(15);                       // waits 15ms for the servo to reach the position
  }
}


void openFlap(Servo &servo, int start_degree, int end_degree){
  //servoFlap.write(180);
  //delay(2000);

  for (pos = start_degree; pos <= end_degree; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    servo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  
}

void sweepTheArm(Servo servoArm){
  // function that sweeps the unloading arm and then brings it back to neutral position
  servoArm.write(90);
  delay(2000);
  servoArm.write(0);
  delay(2000);
}



void liftGoingUp(Adafruit_DCMotor *motor, long motor_speed, long dur){
  // lift goes up until the microswitch on top is pressed
  // run the small motor until this happens
  motor->setSpeed(motor_speed);

  motor->run(FORWARD);
  delay(dur);
  
}

void liftGoingDown(Adafruit_DCMotor *motor, long motor_speed, long dur) {
  motor->setSpeed(motor_speed);

  motor->run(BACKWARD);
  delay(dur);
}
