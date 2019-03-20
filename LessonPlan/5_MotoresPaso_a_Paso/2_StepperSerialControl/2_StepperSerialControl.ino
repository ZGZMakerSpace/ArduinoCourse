/*
  Free open Arduino Course

  Github:
  https://github.com/ZGZMakerSpace/ArduinoCourse
  Documentation:
  https://zaragozamakerspace.com/index.php/courses/curso-basico-arduino/
  
  by Zaragoza Maker Space
*/



#include <Stepper.h>
#include <SoftwareSerial.h>

char serialData;

Stepper motor(200, 5, 6, 9, 10);
SoftwareSerial comm(2,3);

void setup() {
  Serial.begin(9600);
  motor.setSpeed(200);

  serialData = (char)(('0'));

}

void loop() {
  if (Serial.available()) {
    if (serialData == ('U')) {
      motor.step(((comm.readString()).toInt()));
    }
    if (serialData == ('D')) {
      motor.step((((comm.readString()).toInt()) * -1));
    }
    if (serialData == ('V')) {
      motor.setSpeed(((comm.readString()).toInt()));
    }
  }

}
