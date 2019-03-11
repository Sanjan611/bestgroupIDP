void pickUp(){
            Serial.println("Starting mechanism ...");
            delay(2000);
            bringArmToNeutral(servoArm, 0);
            Serial.println("Brought arm to neutral");
            delay(2000);
            liftGoingUp(myMotorLift, 255, 7000);
            Serial.println("Lift went up");
            delay(2000);
            openFlap(servoFlap, 40, 120);
            Serial.println("Flap opened");
            delay(2000);
            liftGoingDown(myMotorLift, 255, 5000);
            Serial.println("Lift went down");
            delay(2000);
            closeFlap(servoFlap, 120, 40);
            Serial.println("Flap closed");
            delay(2000);
            liftGoingUp(myMotorLift, 255, 7000);
            Serial.println("Lift went up");
            delay(2000);
            openFlap(servoFlap, 40, 120);
            Serial.println("Flap opened");
            delay(2000);
            sweepTheArm(servoArm, 0, 120, 5);
            Serial.println("Sweep arm swept");
}
