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
    String filecharname = "test.txt";
    if (SD.exists( filecharname )){
      Serial.println(" Setup test.txt Exists");
    }
  }else {
   Serial.println("SD Initialization failed!");
  }

}

void loop() {

  if (Serial.available() ){
    String filestr = Serial.readString();
    int maxLength = filestr.length();
    

    if ( SD.exists( filestr  )){
      Serial.print("File  ");Serial.println( filestr );
      File entry = SD.open( filestr );
      if (entry){
        Serial.println(" Exists");
        Serial.println();
        int countCR = 0;
        int countLF = 0;
        while (entry.available()) {
          //Serial.print("\t");
          //peek() lee el caracter disponible pero no desplaza el puntero
          //En cambio read() si que desplaza el puntero
          Serial.print( (char)entry.peek() );  //Los valores de CR y LF no aparecen escritos en el monitor serie, pero existen en el fichero.
    
          //Hay diferencia al leerlo como un caracter, a leerlo como un dato no declarado. Por defecto nos aparecera su valor numerico.
          int data = entry.read();
    
          //Cada linea en el fichero termina con un retorno de carro CR y un fin de linea LF.
          //El numero 13 corresponde con el retorno de carro, tambien se representa con "\r".
          if (data== 13){
            
            countCR++;
          }
          
          //El numero 10 corresponde con el fin de linea, tambien se representa con "\n"
          //A partir de este momento, el proximo valor leido es el dato de comienzo de la siguiente linea 
          if (data== 10){
            
            countLF++;
          }
        }
        Serial.println();Serial.println();
        Serial.print("LF: ");Serial.println(countLF);
        Serial.print("CR: ");Serial.println(countCR);
      }else{
        Serial.println("File Not Exists");

      }
    }else{
      Serial.println("String File Not Exists");
    }
    
  }
}
