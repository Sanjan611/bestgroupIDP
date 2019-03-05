bool isHallActive(int hallPin){
  if(digitalRead(hallPin) == HIGH){
    return true;
  }
  else{
    return false;
  }
}

bool isPhotoActive(photoPin){
  if(digitalRead(photoPin) == HIGH) return true;
  else return false;
}

void checkForBlock(){
  if(isPhotoActive == true){
     motor_speed = 100; // slows down when sees block
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
