/*
  Free open Arduino Course

  Github:
  https://github.com/ZGZMakerSpace/ArduinoCourse
  Documentation:
  https://zaragozamakerspace.com/index.php/courses/curso-basico-arduino/
  
  by Zaragoza Maker Space
*/


#include <Servo.h>

boolean auxvar = true;
boolean auxvar_3 = true;
boolean auxvar_2 = true;

Servo motor;

void setup() {

  motor.attach(5);

}

void loop() {
  if( millis() > 1000 && auxvar){
      auxvar = false;
      motor.write(0);

  };
  if( millis() > 2000 && auxvar_3){
      auxvar_3 = false;
      motor.write(180);

  };
  if( millis() > 3000 && auxvar_2){
      auxvar_2 = false;
      motor.write(90);

  };

}


