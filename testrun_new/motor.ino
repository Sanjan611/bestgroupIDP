void moveForward(Adafruit_DCMotor *motor1, long motor_speed_1, Adafruit_DCMotor *motor2, long motor_speed_2, long dur){

  motor1->setSpeed(motor_speed_1);
  motor2->setSpeed(motor_speed_2);

  motor1->run(FORWARD);
  motor2->run(BACKWARD);

  delay(dur);
}

void moveBackwards(Adafruit_DCMotor *motor1, long motor_speed_1, Adafruit_DCMotor *motor2, long motor_speed_2, long dur){

  motor1->setSpeed(motor_speed_1);
  motor2->setSpeed(motor_speed_2);

  motor1->run(BACKWARD);
  motor2->run(FORWARD);

  delay(dur);
}

void turnRight(Adafruit_DCMotor *motor1, long motor_speed_1, Adafruit_DCMotor *motor2, long motor_speed_2, long dur){

  motor1->setSpeed(motor_speed_1);
  motor2->setSpeed(motor_speed_2);

  motor1->run(BACKWARD);
  motor2->run(BACKWARD);

  delay(dur);
}

void turnLeft(Adafruit_DCMotor *motor1, long motor_speed_1, Adafruit_DCMotor *motor2, long motor_speed_2, long dur){

  motor1->setSpeed(motor_speed_1);
  motor2->setSpeed(motor_speed_2);

  motor1->run(FORWARD);
  motor2->run(FORWARD);

  delay(dur);
}
