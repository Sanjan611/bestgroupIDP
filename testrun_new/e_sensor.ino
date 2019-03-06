
bool isPhotoActive(){
  //note photoPin is declared in the main tab
  if(digitalRead(photoPin) == HIGH) return true;
  else return false;
}

bool isHallActive(){
  if(digitalRead(hallPin) == HIGH){
    return true;
  }
  else{
    return false;
  }
}



void checkForBlock(){
  if(isPhotoActive() == true){
     motor_speed = 100; // slows down when sees block
     if(isHallActive() == false){
      // lift descends
      liftGoingDown();
      // flap moves after delay
      //closeFlap();
      // lift ascends
      liftGoingUp();
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

 
