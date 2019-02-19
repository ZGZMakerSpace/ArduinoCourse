/*
  Free open Arduino Course

  Github:
  https://github.com/ZGZMakerSpace/ArduinoCourse
  Documentation:
  https://zaragozamakerspace.com/index.php/courses/curso-basico-arduino/
  
  by Zaragoza Maker Space
*/
int time = 50;

void setup() {
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
}

void loop() {
  
  digitalWrite(2, HIGH);
  
  for (int i=0; i < 255; i++){
     analogWrite( 3, i );
     delay( time );
  }
  
  for (int i=255; i > 0; i--){
     analogWrite( 3, i );
     delay( time );
  }
  digitalWrite(2, LOW);
  
}
