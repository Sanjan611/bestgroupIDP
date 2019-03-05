bool isHallActive(int hallPin){
  if(digitalRead(hallPin) == HIGH){
    return true;
  }
  else{
    return false;
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
