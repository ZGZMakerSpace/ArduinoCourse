/*
  Free open Arduino Course

  Github:
  https://github.com/ZGZMakerSpace/ArduinoCourse
  Documentation:
  https://zaragozamakerspace.com/index.php/courses/curso-basico-arduino/
  
  by Zaragoza Maker Space
*/

void setup() {
  Serial.begin(9600);
  pinMode(A0, INPUT);
}

void loop() {
  Serial.println(analogRead(A0));
}
