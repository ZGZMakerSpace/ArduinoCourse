/*
  Free open Arduino Course

  Github:
  https://github.com/ZGZMakerSpace/ArduinoCourse
  Documentation:
  https://zaragozamakerspace.com/index.php/courses/curso-basico-arduino/
  
  by Zaragoza Maker Space
*/


#include <Servo.h>

int motor_ref;
int motor_vel;
char mode;

Servo motor;

void setup() {
  Serial.begin(9600);

  motor.attach(10);
  motor_ref = (int)(0);
  motor_vel = (int)(90);
  mode = (char)(('/'));

}

void loop() {
  if (Serial.available()) {
    mode = (Serial.read());
    if (mode == ('C')) {
      motor_ref = ((Serial.readString()).toInt());
      Serial.print("Calibrate:");
      Serial.println(motor_ref);
    }
    if (mode == ('M')) {
      motor_vel = ((Serial.readString()).toInt());
    }
    motor.write((motor_vel + motor_ref));
    Serial.print("Move:");
    Serial.println((motor_vel));
  }

}


