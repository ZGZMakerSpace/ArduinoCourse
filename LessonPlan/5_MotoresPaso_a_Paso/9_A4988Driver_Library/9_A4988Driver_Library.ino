/*
  Free open Arduino Course

  Github:
  https://github.com/ZGZMakerSpace/ArduinoCourse
  Documentation:
  https://zaragozamakerspace.com/index.php/courses/curso-basico-arduino/
  
  by Zaragoza Maker Space
*/

#include "A4988.h"
#define MOTOR_STEPS 200
#define RPM 150
#define MICROSTEPS 1
#define ENABLE 4

int STEP = 2;
int DIR = 3;

#define MS1 10
#define MS2 11
#define MS3 12
A4988 stepper(MOTOR_STEPS, DIR, STEP, ENABLE, MS1, MS2, MS3);

char serialData;
void setup() {
  Serial.begin(9600);
  stepper.begin(RPM, MICROSTEPS);
  stepper.enable();
  stepper.setSpeedProfile( stepper.LINEAR_SPEED );
}

void loop() {
  if (Serial.available()){
    serialData = Serial.read();
    if ( serialData == 'P'){
      int degrees = Serial.readString().toInt();
      stepper.rotate(degrees);
      Serial.println("Position in degrees: "+ String(degrees) );
    }
    if ( serialData == 'M'){
      int nsteps = Serial.readString().toInt();
      stepper.move(nsteps);
      Serial.println("Position in steps: "+ String(nsteps) );
    }

    if ( serialData == 'S'){
      stepper.stop();
      Serial.println("Stop ");
    }

    if ( serialData == 'L'){
      stepper.setSpeedProfile( stepper.LINEAR_SPEED );
      Serial.println("LINEAR SPEED " );
    }

    if ( serialData == 'C'){
      stepper.setSpeedProfile( stepper.CONSTANT_SPEED );
      Serial.println("CONSTANT SPEED" );
    }

  }
  
}
