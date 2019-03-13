bool moveToWall(int distance_limit, int distance_no_speed){

  //Serial.println("Start of one loop \n\n\n");

  if(distance > distance_limit){
    motor_speed = 200;        // changed from 255!!
    float motor_speed_left, motor_speed_right;
    if(diff == 0){
      motor_speed_left = motor_speed;
      motor_speed_right = motor_speed;
    }
    else if(rwheel == true){
      motor_speed_left = motor_speed;
      motor_speed_right = motor_speed - kp*diff;
      //Serial.println("adjusting right");
    }
    else{
      motor_speed_left = motor_speed - kp*diff;
      motor_speed_right = motor_speed;
      //Serial.println("adjusting left");
    }
    moveForward(myMotorLeft, motor_speed_left, myMotorRight, motor_speed_right, 10);
    return false;
  }

  else if (distance > distance_no_speed) {
    motor_speed = (distance - distance_no_speed)*(255/(distance_limit - distance_no_speed));
    moveForward(myMotorLeft, motor_speed, myMotorRight, motor_speed, 10);
    return false;
  }

  else{
    stopRLMotors(20, myMotorLeft, myMotorRight);
    return true;
  }
}

/*
  if(distance<10){
    myMotor->setSpeed(150);
    myMotor1->setSpeed(150);
    myMotor->run(BACKWARD);
    myMotor1->run(FORWARD);
  }
*/
