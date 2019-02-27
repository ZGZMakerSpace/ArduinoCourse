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
boolean state;

void setup() {
  Serial.begin(9600);
  pinMode(buttonPin, INPUT);
  pinMode(LEDpin, OUTPUT);

  LEDpin = (int)(3);
  buttonPin = (int)(4);
  sum = (int)(0);
  state = (boolean)(false);

}

void loop() {
  if (state != digitalRead(buttonPin)) {
    state = digitalRead(buttonPin);
    if (state == true) {
      digitalWrite(LEDpin, HIGH);
      sum = sum + 1;
      Serial.println(sum);
    } else {
      digitalWrite(LEDpin, LOW);
    }
  }

}
