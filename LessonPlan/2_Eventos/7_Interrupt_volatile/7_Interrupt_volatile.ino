/*
  Free open Arduino Course

  Github:
  https://github.com/ZGZMakerSpace/ArduinoCourse
  Documentation:
  https://zaragozamakerspace.com/index.php/courses/curso-basico-arduino/
  
  by Zaragoza Maker Space
*/

int LEDpin = 4;
int sum = 0;

void isr(){
   
   sum= sum +1;
   Serial.println(sum);
};
  

void setup() {
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(2),isr, RISING);

}

void loop() {


}


