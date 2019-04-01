/*
  Free open Arduino Course

  Github:
  https://github.com/ZGZMakerSpace/ArduinoCourse
  Documentation:
  https://zaragozamakerspace.com/index.php/courses/curso-basico-arduino/
  
  by Zaragoza Maker Space
*/

#include <Stepper.h>

char serialData;

Stepper motor(200, 5, 6, 9, 10);

void setup() {
  Serial.begin(9600);
  motor.setSpeed(200);

  serialData = (char)(('0'));

}

void loop() {
  if (Serial.available()) {
    serialData = Serial.read();
    if (serialData == ('U')) {
      motor.step(((Serial.readString()).toInt()));
    }
    if (serialData == ('D')) {
      motor.step((((Serial.readString()).toInt()) * -1));
    }
    if (serialData == ('V')) {
      motor.setSpeed(((Serial.readString()).toInt()));
    }
  }

}
