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


void setup() {
  Serial.begin( 9600 );
  pinMode(SDpin, OUTPUT);
  
  if ( SD.begin( SDpin ) ){
    Serial.println("SD SUCCESS");
    
  }else {
   Serial.println("SD Initialization failed!");
  }

}

void loop() {

  if (Serial.available() ){
    String filestr = Serial.readString();

    if ( SD.exists( filestr  )){
      Serial.print("File  ");Serial.println( filestr );
      File entry = SD.open( filestr );
      
      if (entry){
        Serial.println(" Exists");
        Serial.println();

        while (entry.available()) {
          Serial.print( (char)entry.read() ); 
        }
        entry.close();
      }else{
        Serial.println("File Not Exists");

      }
    }else{
      File entry = SD.open( filestr, FILE_WRITE);
      Serial.println();
      Serial.print("Write what you want to store in SD File:");
      Serial.println(filestr);
      while ( !Serial.available() ){
        
      }
      String serialData = Serial.readString();
      entry.println(serialData);
      Serial.println("Data stores: Now, you can read your new File");
      
      entry.close();
    }
    
  }
}
