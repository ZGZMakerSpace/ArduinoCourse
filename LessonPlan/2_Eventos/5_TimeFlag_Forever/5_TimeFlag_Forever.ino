/*
  Free open Arduino Course

  Github:
  https://github.com/ZGZMakerSpace/ArduinoCourse
  Documentation:
  https://zaragozamakerspace.com/index.php/courses/curso-basico-arduino/
  
  by Zaragoza Maker Space
*/

unsigned long flag;

void setup() {
  Serial.begin(9600);
}

void loop() {
  if( millis() - flag > 5000){
    flag = millis();
    Serial.print("Time: ");
    Serial.println(millis());
  };

}


