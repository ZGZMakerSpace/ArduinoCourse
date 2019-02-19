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
bool state = false;

void setup() {
  Serial.begin(9600);
  pinMode(LEDpin, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop() {
  
  if ( analogRead(buttonPin) != state ){
    state = analogRead(buttonPin);
    digitalWrite( LEDpin, state );
    Serial.print("State changed to : ");
    Serial.println(state);    
  }
  
}
