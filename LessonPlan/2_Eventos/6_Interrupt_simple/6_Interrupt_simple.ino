/*
  Free open Arduino Course

  Github:
  https://github.com/ZGZMakerSpace/ArduinoCourse
  Documentation:
  https://zaragozamakerspace.com/index.php/courses/curso-basico-arduino/
  
  by Zaragoza Maker Space
*/

boolean state;
int LEDpin = 4;

void isr(){
   
   digitalWrite(LEDpin, state);
   Serial.println("CHANGE");
};
  

void setup() {
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(2),isr, CHANGE);

}

void loop() {


}


