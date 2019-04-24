/*
  Free open Arduino Course

  Github:
  https://github.com/ZGZMakerSpace/ArduinoCourse
  Documentation:
  https://zaragozamakerspace.com/index.php/courses/curso-basico-arduino/
  
  by Zaragoza Maker Space
*/
#include <SD.h>
const byte SDpin = 3;
unsigned long auxtimer;

void setup() {
  Serial.begin( 9600 );
  pinMode(SDpin, OUTPUT);
  SDClass SD; 
  
  if ( SD.begin( SDpin ) ){
    Serial.println("SD SUCCESS");
  }
  else {
   Serial.println("SD Initialization failed!");
   
  }
}

void loop() {
  if( millis() - auxtimer > 500){
    auxtimer = millis();
 
    if ( SD.begin( SDpin ) ){
      Serial.println("SD SUCCESS");
    }
    else {
      Serial.println("SD Initialization failed!");
     
    }
  };
}
