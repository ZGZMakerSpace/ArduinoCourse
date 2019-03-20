/*
  Free open Arduino Course

  Github:
  https://github.com/ZGZMakerSpace/ArduinoCourse
  Documentation:
  https://zaragozamakerspace.com/index.php/courses/curso-basico-arduino/
  
  by Zaragoza Maker Space
*/

#include <Stepper.h>

int actual_pos;
int dir;
int steps;
int position;

Stepper motor(200, 5, 6, 9, 10);

void setup() {
  Serial.begin(9600);
  motor.setSpeed(100);

  actual_pos = (int)(0);
  dir = (int)(1);
  steps = (int)(5);
  position = (int)(500);

}

void loop() {
  actual_pos = actual_pos + dir * steps;
  motor.step((dir * steps));
  Serial.println(actual_pos);
  if (actual_pos == position) {
    dir = -dir;
    position = -position;
    Serial.println("Change Direction");
    Serial.println(dir);
  }

}




