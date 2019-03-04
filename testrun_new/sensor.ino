bool isHallActive(int hallPin){
  if(digitalRead(hallPin) == HIGH){
    return true;
  }
  else{
    return false;
  }
}
