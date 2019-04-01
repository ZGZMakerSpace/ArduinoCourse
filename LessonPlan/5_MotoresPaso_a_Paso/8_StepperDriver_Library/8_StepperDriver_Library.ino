/*
  Free open Arduino Course

  Github:
  https://github.com/ZGZMakerSpace/ArduinoCourse
  Documentation:
  https://zaragozamakerspace.com/index.php/courses/curso-basico-arduino/
  
  by Zaragoza Maker Space
*/
#include "BasicStepperDriver.h"

// Motor steps per revolution. Most steppers are 200 steps or 1.8 degrees/step
#define MOTOR_STEPS 200
#define RPM 100
#define MICROSTEPS 2

int STEP = 2;
int DIR = 3;

BasicStepperDriver stepper(MOTOR_STEPS, DIR, STEP);

char serialData;
void setup() {
  Serial.begin(9600);
  stepper.begin(RPM, MICROSTEPS);
  stepper.enable();
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

  }
  
}
