long get_distance(int whichSensor){ // 1 for front, 2 for side
  if(whichSensor == 1){
    trigPin = trigPinFront;
    echoPin = echoPinFront;
  }
  else if(whichsensor == 2){
    trigPin = trigPinSide;
    echoPin = echoPinSide;
  }
  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance= duration*0.034/2;

  return distance;
}
