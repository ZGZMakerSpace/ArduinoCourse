/*
  Free open Arduino Course

  Github:
  https://github.com/ZGZMakerSpace/ArduinoCourse
  Documentation:
  https://zaragozamakerspace.com/index.php/courses/curso-basico-arduino/
  
  by Zaragoza Maker Space
*/

#include <AccelStepper.h>

char serialData;
unsigned long auxtimer;

AccelStepper stepper_motor(4,5,6,9,10);

void setup() {
  Serial.begin(9600);

  serialData = (char)(('0'));
  delay(2000);
  stepper_motor.setSpeed(300);
  stepper_motor.setAcceleration(100);
  stepper_motor.setMaxSpeed(600);
  stepper_motor.moveTo(5000);

}

void loop() {
  if( millis() - auxtimer > 100){
    auxtimer = millis();
    Serial.println((String(stepper_motor.currentPosition()) + String(",") + String(stepper_motor.speed())));
  };
  stepper_motor.run();

}


