/*
  Free open Arduino Course

  Github:
  https://github.com/ZGZMakerSpace/ArduinoCourse
  Documentation:
  https://zaragozamakerspace.com/index.php/courses/curso-basico-arduino/
  
  by Zaragoza Maker Space
*/

#include <AccelStepper.h>
#define HALFSTEP 4
 
// Motor pin definitions
#define motorPin1  5
#define motorPin2  6
#define motorPin3  9
#define motorPin4  10
 
// Initialize with pin sequence IN1-IN3-IN2-IN4 for using the AccelStepper
AccelStepper stepperMotor(HALFSTEP, motorPin1, motorPin2, motorPin3, motorPin4);
 
void setup() {
  stepperMotor.setMaxSpeed(600.0);
  stepperMotor.setAcceleration(100.0);
  stepperMotor.setSpeed(300);
  stepperMotor.moveTo(1000);
 
}//--(end setup )---
 
void loop() {
 
  //Change direction when the stepper reaches the target position
  if (stepperMotor.distanceToGo() == 0) {
    stepperMotor.moveTo(-stepperMotor.currentPosition());
  }
  stepperMotor.run();
}
