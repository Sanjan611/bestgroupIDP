void moveForward(Adafruit_DCMotor *motor1, long motor_speed_1, Adafruit_DCMotor *motor2, long motor_speed_2, long dur){
  /*
   * Function to move forward
   */

  motor1->setSpeed(motor_speed_1-4);
  motor2->setSpeed(motor_speed_2);

  motor1->run(BACKWARD);
  motor2->run(FORWARD);

  delay(dur);
}

void moveBackwards(Adafruit_DCMotor *motor1, long motor_speed_1, Adafruit_DCMotor *motor2, long motor_speed_2, long dur){
  /*
   * Function to move backwards
   */

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
  /*
   * Function to turn right
   */

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

void stopLiftMotor(Adafruit_DCMotor *motor, long dur){
  motor->setSpeed(0);

  motor->run(RELEASE);

  delay(dur);
}


void stopRLMotors(long dur, Adafruit_DCMotor *motor1, Adafruit_DCMotor *motor2){
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
  end_degree = 110;
  servo.write(end_degree);   // NEW BIT TESTED
  return;
  
  for (pos = start_degree; pos <= end_degree; pos += 3) { // goes from 180 degrees to 0 degrees
     servo.write(pos);              // tell servo to go to position in variable 'pos'
     delay(15);                       // waits 15ms for the servo to reach the position
  }
}


void openFlap(Servo &servo, int start_degree, int end_degree){
  //servoFlap.write(180);
  //delay(2000);

  servo.write(end_degree);     // nEW BIT TESTED
  return;

  for (pos = start_degree; pos >= end_degree; pos -= 3) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    servo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  
}

void bringArmToNeutral(Servo servo,int initial){

  servo.write(initial);
}

void sweepTheArm(Servo servo, int initial, int final, int sweep_step){
  // function that sweeps the unloading arm and then brings it back to neutral position
  // what works - initial = 0, final = 120, sweep_step = 5

  servo.write(0);

  // sweeping the arm to take off all the blocks collected
  for (pos = initial; pos <= final; pos += sweep_step) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    servo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);  // waits 15ms for the servo to reach the position
  }

  delay(5000);

  // sweeping the arm back to its original position
  for (pos = final; pos >= initial; pos -= sweep_step) { // goes from 180 degrees to 0 degrees
    servo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }

  delay(3000);
}



void liftGoingUp(Adafruit_DCMotor *motor, long motor_speed, long dur){
  /*
   * Function to bring the lift up
   * The lift pulley motor is connected to M3 on the motor shield
   */
  // lift goes up until the microswitch on top is pressed
  // run the small motor until this happens
  /*
  if(isMicroswitchPressed == true){
    motor->setSpeed(0);
  }
  else 
  */
  motor->setSpeed(motor_speed);
  Serial.println("lift ascending.....");
  
  

  while(isMicroswitchPressed(microPin)==false){
    motor->run(BACKWARD);
    
  }
  

  Serial.println("Switch has been pressed");
  motor->run(RELEASE);
 
  
}

void liftGoingDown(Adafruit_DCMotor *motor, long motor_speed, long dur) {
  /*
   * Function to bring the lift down
   * The lift pulley motor is connected to M3 on the motor shield
   */
  motor->setSpeed(motor_speed);

  motor->run(FORWARD);
  delay(dur);
  motor->setSpeed(0);
  motor->run(RELEASE);
}
