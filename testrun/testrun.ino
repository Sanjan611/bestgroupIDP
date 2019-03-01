

#include <Wire.h>
#include <Adafruit_MotorShield.h>

Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 


Adafruit_DCMotor *myMotor = AFMS.getMotor(1);
Adafruit_DCMotor *myMotor1 = AFMS.getMotor(2);

const int trigPin = 9; // Trigger Pin of Ultrasonic Sensor
const int echoPin = 10; // Echo Pin of Ultrasonic Sensor
long duration = 0;
long distance = 0;
float motor_speed = 0;
int distance_limit = 30;
int distance_no_speed = 10;

void setup() {
  Serial.begin(9600);         
  Serial.println("Adafruit Motorshield v2 - DC Motor test!");

  AFMS.begin();  // create with the default frequency 1.6KHz

  myMotor->run(RELEASE);

  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT);
}

void loop() {
  uint8_t i;

  distance = get_distance(); 


  Serial.println(distance);

  Serial.print("tick");

  if(distance > distance_limit){
    Serial.println("Inside the IF");
    motor_speed = 255;
    myMotor->setSpeed(motor_speed);
    myMotor1->setSpeed(motor_speed);
    myMotor->run(FORWARD);
    myMotor1->run(BACKWARD);
    delay(10);
  }

  else{
    Serial.println("Inside the ELSE");
    motor_speed = (distance - distance_no_speed)*(255/(distance_limit - distance_no_speed));
    myMotor->setSpeed(motor_speed);
    myMotor1->setSpeed(motor_speed);
    myMotor->run(FORWARD);
    myMotor1->run(BACKWARD);
    delay(10);
  }

  Serial.println(" NOT Releasing the motors now!");
  //myMotor->run(RELEASE);
  //myMotor1->run(RELEASE);
  
  //delay(5000);

  Serial.println("End of one loop \n\n\n");

  
}
