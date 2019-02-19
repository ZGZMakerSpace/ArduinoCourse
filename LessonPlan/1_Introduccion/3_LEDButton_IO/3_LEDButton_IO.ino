/*
  Free open Arduino Course

  Github:
  https://github.com/ZGZMakerSpace/ArduinoCourse
  Documentation:
  https://zaragozamakerspace.com/index.php/courses/curso-basico-arduino/
  
  by Zaragoza Maker Space
*/

int LEDpin = 2;
int buttonPin = 3;

void setup() {
  Serial.begin(9600);
  pinMode(LEDpin, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop() {
  
  if ( analogRead(buttonPin) == HIGH ){
    digitalWrite( LEDpin, HIGH );
  }else{
    digitalWrite( LEDpin, LOW );
  }
  
}
