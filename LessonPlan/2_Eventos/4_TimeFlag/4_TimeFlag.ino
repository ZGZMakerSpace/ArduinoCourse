/*
  Free open Arduino Course

  Github:
  https://github.com/ZGZMakerSpace/ArduinoCourse
  Documentation:
  https://zaragozamakerspace.com/index.php/courses/curso-basico-arduino/
  
  by Zaragoza Maker Space
*/

int LEDpin;
boolean flag;
long current_time;

void setup() {
  Serial.begin(9600);
  pinMode(LEDpin, OUTPUT);

  LEDpin = (int)(3);
  flag = (boolean)(true);
  current_time = (long)(0);

}

void loop() {
  current_time = millis();
  if (current_time > 5000 && flag) {
    flag = false;
    digitalWrite(LEDpin, HIGH);
    Serial.println("LED ON");
  }

}


