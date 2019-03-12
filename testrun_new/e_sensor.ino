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



bool checkForBlock(){
 
  if(isPhotoActive() == true){
    return true;
  }
   else{
    return false;
   }
}


 
