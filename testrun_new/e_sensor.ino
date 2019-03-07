bool isPhotoActive(){
  /*
   *  Function to check if the photo transistor is active or not.
   *  This is used when we need to check if there is a block or not.
   */
  //note photoPin is declared in the main tab
  if(digitalRead(photoPin) == HIGH) return true;
  else return false;
}

bool isHallActive(){
  /*
   * Function to check if the hall sensor is active or not
   * We can know if the block is magnetic or not
   */
  if(digitalRead(hallPin) == HIGH){
    return true;
  }
  else{
    return false;
  }
}

bool isMicroswitchPressed(int microPin){
  /*
   * Function to check if the microswitch is pressed
   * The microswitch is at the ceiling point of the lift
   * to check when the lift is at the top most position
   */

  if(digitalRead(microPin)==HIGH){
    return true;
  }
  else return false;
  
}



void checkForBlock(){
  
  if(isPhotoActive() == true){
     motor_speed = 100; // slows down when sees block

     if(isHallActive() == false){
      // lift descends
//      liftGoingDown();
      // flap moves after delay
      //closeFlap();
      // lift ascends
      //liftGoingUp();
      // flap moves back to original position
      //openFlap();
     }
     else{
      // block is magnetic, doesn't have to be picked up
      // keep going
      // make sure that the lift is up
     }
   }
  else{
     motor_speed = 255; // max speed while no block is detected
   }
}


/*
 *
 * hall = isHallActive(hallPin);
  if(hall==true){
    Serial.println("YES IT IS WORKING!");
  }
  else{
    Serial.println("NOPE");
  }

  delay(500);
 */

 
