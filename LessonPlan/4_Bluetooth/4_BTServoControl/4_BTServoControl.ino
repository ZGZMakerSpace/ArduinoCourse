/*
  Free open Arduino Course

  Github:
  https://github.com/ZGZMakerSpace/ArduinoCourse
  Documentation:
  https://zaragozamakerspace.com/index.php/courses/curso-basico-arduino/
  
  by Zaragoza Maker Space
*/



#include <SoftwareSerial.h>
#include <Servo.h>

char BTData;
int servoMin;
int servoMax;
int servoValue;

SoftwareSerial comm(2,3);
Servo motor;

void setup() {
  Serial.begin(9600);
  comm.begin(9600);

  BTData = (char)((' '));
  servoMin = (int)(40);
  servoMax = (int)(115);
  servoValue = (int)(0);
  motor.attach(10);

}

void loop() {
  if (comm.available()) {
    BTData = (comm.read());
    Serial.println(BTData);
    if (BTData == ('C')) {
      servoValue = ((comm.readString()).toInt());
      motor.write((map(servoValue,10, 55, servoMin , servoMax)));
    }
  }

}


