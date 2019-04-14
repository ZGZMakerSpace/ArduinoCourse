/*
  Free open Arduino Course

  Github:
  https://github.com/ZGZMakerSpace/ArduinoCourse
  Documentation:
  https://zaragozamakerspace.com/index.php/courses/curso-basico-arduino/
  
  by Zaragoza Maker Space
*/
int ZMS_intarray[] ={ 90, 77, 83};
char ZMS_chararray[] ={ 'Z', 'M','S'};

void setup() {
  Serial.begin(9600);
  
  Serial.println("Int array: ");
  for(int i = 0; i < 3 ; i++ ){
    Serial.print( ZMS_intarray[i] );
  }
  Serial.println();
  Serial.println("Char array: ");
  for(int i = 0; i < 3 ; i++ ){
    Serial.print( ZMS_chararray[i] );
  } 
  Serial.println();
  
  Serial.println("Convert int to char: ");
  
  for(int i = 0; i < 3 ; i++ ){
    
    Serial.print( (char)ZMS_intarray[i] );
  } 
  
}

void loop() {
  
}
