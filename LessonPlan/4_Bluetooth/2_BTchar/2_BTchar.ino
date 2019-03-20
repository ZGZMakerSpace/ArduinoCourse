/*
  Free open Arduino Course

  Github:
  https://github.com/ZGZMakerSpace/ArduinoCourse
  Documentation:
  https://zaragozamakerspace.com/index.php/courses/curso-basico-arduino/
  
  by Zaragoza Maker Space
*/

#include <SoftwareSerial.h>

char BTData;

SoftwareSerial comm(10,11);

void setup() {
  Serial.begin(9600);
  comm.begin(9600);

  BTData = (char)((' '));

}

void loop() {
  if (comm.available()) {
    BTData = (comm.read());
    Serial.println(BTData);
  }

}

