/*
  Free open Arduino Course

  Github:
  https://github.com/ZGZMakerSpace/ArduinoCourse
  Documentation:
  https://zaragozamakerspace.com/index.php/courses/curso-basico-arduino/
  
  by Zaragoza Maker Space
*/

int LEDpin;
int buttonPin;
int sum;

void setup() {
  Serial.begin(9600);
  pinMode(buttonPin, INPUT);
  pinMode(LEDpin, OUTPUT);

  LEDpin = (int)(3);
  buttonPin = (int)(4);
  sum = (int)(0);

}

void loop() {
  if (digitalRead(buttonPin) == true) {
    digitalWrite(LEDpin, HIGH);
    sum = sum + 1;
    Serial.println(sum);
  } else {
    digitalWrite(LEDpin, LOW);
  }

}
