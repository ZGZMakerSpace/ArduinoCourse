/*
  Free open Arduino Course

  Github:
  https://github.com/ZGZMakerSpace/ArduinoCourse
  Documentation:
  https://zaragozamakerspace.com/index.php/courses/curso-basico-arduino/
  
  by Zaragoza Maker Space
*/

long current_time;

void process() {
  delay(2000);
}

void setup() {
  Serial.begin(9600);

  current_time = (long)(0);

}

void loop() {
  current_time = millis();
  process();
  Serial.println(current_time);

}


