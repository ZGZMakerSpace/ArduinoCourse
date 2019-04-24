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
    File root = SD.open("/");
    if (root.isDirectory()) {
      while (true) {
         File entry =  root.openNextFile();
         if (! entry) {
          // no more files
          break;
          }
          if (entry.isDirectory()) {
            Serial.print( "D - " );
          }
          Serial.print( entry.name() );
          Serial.print("\t\t");
          Serial.println(entry.size(), DEC);
          
      }
    }
  }
  else {
   Serial.println("SD Initialization failed!");
  }
  Serial.println();
  Serial.println("SD Done");
  
}

void loop() {

}
