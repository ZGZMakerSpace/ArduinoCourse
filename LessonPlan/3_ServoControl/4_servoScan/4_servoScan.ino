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
long time;
int motor_pos;
int motor_step;
int direction;

Servo motor;

void setup() {
  Serial.begin(9600);

  motorPin = (int)(10);
  motor.attach(motorPin);
  time = (long)(0);
  
  motor_pos = (int)(motor.read());
  motor_step = (int)(2);
  direction = (int)(1);
}

void loop() {
  time = millis();
  
  motor_pos = motor_pos + direction * motor_step;
  motor.write(motor_pos);

  if (motor.read() >= 180) {
    direction = -1;
  }
  if (motor.read() <= 0) {
    direction = 1;
  }
  Serial.print("Time: ");
  Serial.println((millis() - time));

}


