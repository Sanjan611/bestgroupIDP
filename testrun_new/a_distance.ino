int trigPin, echoPin;

float get_distance(int whichSensor){
  /*
   * Function to get the distance as measured by the ultrasound sensors
   * By passing argument as 1 or 2, you can get the distance for the 
   * front or the side ultrasound respectively
   */

   
  if(whichSensor == 1){
    trigPin = trigPinFront;
    echoPin = echoPinFront;
  }
  else if(whichSensor == 2){
    trigPin = trigPinSide;
    echoPin = echoPinSide;
  }
  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration*0.034/2.0;

  return distance;
}
