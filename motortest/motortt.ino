

void move_till(bool keepgoing){
  if(keepgoing == true){
    for (i=0; i<255; i++) {
      rightmotor->setSpeed(i);
      leftmotor->setSpeed(i);
      delay(3);
    }
  }
  else{
    for (i=255; i!=0; i--) {
      rightmotor->setSpeed(i);
      leftmotor->setSpeed(i);
      delay(1);
    }
  }
}

// Main two motor controls
void move_forward(bool keepgoing){
  rightmotor->run(FORWARD);
  leftmotor->run(BACKWARD);
  move_till(keepgoing);
}
/*
void move_backward(bool back_switch){
  left_motor->run(FORWARD);
  right_motor->run(BACKWARD);
  move_till_switch(back_switch);
}

void turn_right(){
  // single wheel drive
}

void turn_left(){
  // single wheel drive
}

// Lift motor
void lift_up(bool is_max_up){
  while(is_max_up == false){
    // lift goes up until hits top of the shaft
  }
}
void lift_down(bool is_max_down){
  while(is_max_down == false){
    // lift goes down until hits bottom of the shaft
  }
}
*/
