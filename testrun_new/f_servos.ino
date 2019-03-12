void pickUp(){
            Serial.println("Starting mechanism ...");
            delay(1000);
            
            liftGoingUp(myMotorLift, 255, 7000);
            Serial.println("Lift went up");
            delay(1000);
            
            openFlap(servoFlap, 40, 120);
            Serial.println("Flap opened");
            delay(1000);
            
            liftGoingDown(myMotorLift, 255, 5000);
            Serial.println("Lift went down");
            delay(1000);
            
            closeFlap(servoFlap, 120, 40);
            Serial.println("Flap closed");
            delay(1000);
            
            liftGoingUp(myMotorLift, 255, 7000);
            Serial.println("Lift went up");
            delay(1000);
            
            openFlap(servoFlap, 40, 120);
            Serial.println("Flap opened");
            delay(1000);
}
