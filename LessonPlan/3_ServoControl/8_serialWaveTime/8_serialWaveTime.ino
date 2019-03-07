/*
  Free open Arduino Course

  Github:
  https://github.com/ZGZMakerSpace/ArduinoCourse
  Documentation:
  https://zaragozamakerspace.com/index.php/courses/curso-basico-arduino/
  
  by Zaragoza Maker Space
*/

#include <Servo.h>

int A;
int T;
int O;
int position;
unsigned long auxtimer;

Servo motor;

void setup() {
  Serial.begin(9600);

  motor.attach(11);
  A = (int)(100);
  T = (int)(3000);
  O = (int)(100);
  position = (int)(0);

}

void loop() {
  if( millis() - auxtimer > 50){
    auxtimer = millis();
    position = A * sin((((2 * M_PI) / T) * millis() + O ) );
    position = (map(position,-1 * A, A, 90 - A/2 , (90 + A/2)));
    Serial.println(position);
    motor.write(position);

  };

}

