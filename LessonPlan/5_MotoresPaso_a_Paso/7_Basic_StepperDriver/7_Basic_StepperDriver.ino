/*
  Free open Arduino Course

  Github:
  https://github.com/ZGZMakerSpace/ArduinoCourse
  Documentation:
  https://zaragozamakerspace.com/index.php/courses/curso-basico-arduino/
  
  by Zaragoza Maker Space
*/

int STEP = 2;
int DIR = 3;

int MS1 = 4;
int MS2 = 5;
int EN = 6;

int STEPS = 200;
bool direction = true;
int pos = 0;
int timedelay = 1000;
int stepmode = 0;
char serialData;

void setup() {
  Serial.begin(9600);
  pinMode(DIR, OUTPUT);
  pinMode(STEP, OUTPUT);
  pinMode(MS1, OUTPUT);
  pinMode(MS2, OUTPUT);
  pinMode(EN, OUTPUT);
  digitalWrite(EN, LOW);
  digitalWrite(MS1, LOW);
  digitalWrite(MS2, LOW);
}

void loop() {
  if (Serial.available()){
    serialData = Serial.read();

    if ( serialData == 'P'){
      int nsteps = Serial.readString().toInt();
      int i = 0; 
      while( i < nsteps )  { 
          digitalWrite(STEP, LOW);
          digitalWrite(STEP, HIGH);
          delayMicroseconds( timedelay );     // This delay time determines the speed of the stepper motor. 
          i++;                      
      }  
      Serial.println("Position: "+ String(nsteps) );
    }

    if ( serialData == 'D'){
      direction = !direction;
      digitalWrite(DIR, direction);
      Serial.println("Direction: "+ String(direction) );
    }

    if ( serialData == 'V'){
       timedelay = Serial.readString().toInt();
       Serial.println("Delay Time: "+ String(timedelay) +" microseconds"  );
    }
    
    if ( serialData == 'M'){
      int mode = Serial.readString().toInt();
      digitalWrite(MS1, mode%2);
      digitalWrite(MS2, mode/2);
      Serial.println("Mode: "+ String(mode)+" Steps/rev: "+ (mode+1)*200 );
    }
    
  }
}
