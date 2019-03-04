/*
void nothing(){
  uint8_t i;

  distance = get_distance(); 


  Serial.println(distance);

  Serial.print("tick");

  if(distance > distance_limit){
    Serial.println("Inside the IF");
    motor_speed = 255;
    moveForward(myMotor, motor_speed, myMotor1, motor_speed, 10);
  
  }

  else{
    Serial.println("Inside the ELSE");
    motor_speed = (distance - distance_no_speed)*(255/(distance_limit - distance_no_speed));
    moveForward(myMotor, motor_speed, myMotor1, motor_speed, 10);
  
  }

  Serial.println(" NOT Releasing the motors now!");
  //myMotor->run(RELEASE);
  //myMotor1->run(RELEASE);
  
  //delay(5000);

  Serial.println("End of one loop \n\n\n");

  if(distance<10){
    myMotor->setSpeed(150);
    myMotor1->setSpeed(150);
    myMotor->run(BACKWARD);
    myMotor1->run(FORWARD);
  }
}
*/
