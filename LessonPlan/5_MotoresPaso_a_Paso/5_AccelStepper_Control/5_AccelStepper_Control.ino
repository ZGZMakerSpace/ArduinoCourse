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
AccelStepper stepper(HALFSTEP, motorPin1, motorPin2, motorPin3, motorPin4);

void setup()
{  
  Serial.begin(9600);
    stepper.setMaxSpeed(1000.0);
    stepper.setAcceleration(100.0);
    stepper.setSpeed(600);
}

void loop()
{  
  if (Serial.available()){

    int serialData = Serial.read();
    Serial.println(char(serialData));
    if( serialData== 'A'){
      int val = Serial.readString().toInt();
      stepper.setAcceleration(val);
      Serial.print("Accel: ");Serial.println( val);
    }
    
    if( serialData== 'S'){
      int val = Serial.readString().toInt();
      stepper.setMaxSpeed(val);
      Serial.print("Vel: ");Serial.println( val );

    }

    if( serialData== 'V'){
      int val = Serial.readString().toInt();
      stepper.setSpeed(val);
      Serial.print("Vel: "); Serial.println( stepper.speed() );
    }

    if( serialData== 'P'){
      int val = Serial.readString().toInt();
      Serial.print("Absolute Position: ");Serial.println( val );
      stepper.moveTo(val);
      Serial.print("Absolute Position from: ");Serial.print( stepper.currentPosition() );
      Serial.print(" to: ");Serial.println( stepper.targetPosition() );

    }

    if( serialData== 'R'){
      int val = Serial.readString().toInt();
      Serial.print("Relative Position: ");Serial.println( val);
      stepper.move(val);
      Serial.print("Movement from: ");Serial.print( stepper.currentPosition() );
      Serial.print(" to: ");Serial.println( stepper.targetPosition() );

    }

    if( serialData== 'D'){
      
      stepper.disableOutputs();
      Serial.println("Disable Motors: ");
    }

    if( serialData== 'E'){
      
      stepper.enableOutputs();
      Serial.println("Enable Motors: ");
    }

    if( serialData== 'Q'){
      
      Serial.print("Current Position: ");Serial.println(stepper.currentPosition());
      Serial.print("Target Position: ");Serial.println(stepper.targetPosition());
      Serial.print("Distance: ");Serial.println(stepper.distanceToGo());
      Serial.print("Actual Speed: ");Serial.println(stepper.speed());
    }
  }

  if( stepper.targetPosition() != stepper.currentPosition() ) {
    stepper.run();
  }
  

}
