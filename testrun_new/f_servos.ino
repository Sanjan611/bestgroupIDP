void pickUp(){
            Serial.println("Starting mechanism ...");
            //delay(1000);

            //liftGoingDown(myMotorLift, 255, 9000);
            //Serial.println("Lift went down");
            //delay(500);

            closeFlap(servoFlap, 40, 120);
            Serial.println("Flap closed");
            delay(500);
            
            liftGoingUp(myMotorLift, 255, 10000);
            Serial.println("Lift went up");
            delay(500);

            /*
             * Commented since the flap is already open!
            openFlap(servoFlap, 120, 40);
            Serial.println("Flap opened");
            delay(1000);
            */

            /*
            liftGoingDown(myMotorLift, 255, 9000);
            Serial.println("Lift went down");
            delay(1000);
            
            closeFlap(servoFlap, 40, 120);
            Serial.println("Flap closed");
            delay(1000);
            */

            /*
            
            liftGoingUp(myMotorLift, 255, 10000);
            Serial.println("Lift went up");
            delay(1000);
            */

            /*
            openFlap(servoFlap, 120, 40);
            Serial.println("Flap opened");
            delay(1000);
            */
}
