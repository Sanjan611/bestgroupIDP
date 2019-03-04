bool moveToWall(int distance_limit, int distance_no_speed){

  distance = get_distance(); 

  Serial.println(distance);

  Serial.print("tick");

  Serial.println("Start of one loop \n\n\n");

  if(distance > distance_limit){
    Serial.println("Inside the IF");
    motor_speed = 255;
    moveForward(myMotorLeft, motor_speed, myMotorRight, motor_speed, 10);
    return false;
  }

  else if (distance > distance_no_speed) {
    Serial.println("Inside the ELSE");
    motor_speed = (distance - distance_no_speed)*(255/(distance_limit - distance_no_speed));
    moveForward(myMotorLeft, motor_speed, myMotorRight, motor_speed, 10);
    return false;
  }

  else{
    stopMotor(myMotorLeft, myMotorRight, 2000);
    return true;
  }

  

/*
  if(distance<10){
    myMotor->setSpeed(150);
    myMotor1->setSpeed(150);
    myMotor->run(BACKWARD);
    myMotor1->run(FORWARD);
  }
  */
}
