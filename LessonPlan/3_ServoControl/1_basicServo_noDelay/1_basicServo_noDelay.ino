/*
  Free open Arduino Course

  Github:
  https://github.com/ZGZMakerSpace/ArduinoCourse
  Documentation:
  https://zaragozamakerspace.com/index.php/courses/curso-basico-arduino/
  
  by Zaragoza Maker Space
*/

#include <Servo.h>

int motorPin;
int i;

Servo motor;

void setup() {

  motorPin = (int)(10);
  motor.attach(motorPin);

}

void loop() {
  for (i = 0; i <= 180; i++) {
    motor.write(i);
  }
  for (i = 180; i >= 0; i--) {
    motor.write(i);
  }

}



