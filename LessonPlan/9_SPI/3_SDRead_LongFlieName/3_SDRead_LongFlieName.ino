/*
  Free open Arduino Course

  Github:
  https://github.com/ZGZMakerSpace/ArduinoCourse
  Documentation:
  https://zaragozamakerspace.com/index.php/courses/curso-basico-arduino/
  
  by Zaragoza Maker Space
*/
#include "SdFat.h"
const byte SDpin = 3;

SdFat sd;
SdFile dirFile;

void setup() {
  Serial.begin( 9600 );
  pinMode(SDpin, OUTPUT);
  
  if ( !sd.begin( SDpin, SD_SCK_MHZ(50)) ) {
    sd.initErrorHalt();
  }else{
    Serial.println("SD SUCCESS");
  }

  if (!dirFile.open("/", O_READ)) {
    sd.errorHalt("open root failed");
  }else{
    
      SdFile entry;
      while ( entry.openNext(&dirFile, O_READ) ) {
        
         entry.printName(&Serial);
         Serial.println();
         entry.close();   
      }
    
  }

  Serial.println();
  Serial.println("SD Done");
  
}

void loop() {

}
