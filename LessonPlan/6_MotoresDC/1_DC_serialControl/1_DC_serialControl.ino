/*
  Free open Arduino Course

  Github:
  https://github.com/ZGZMakerSpace/ArduinoCourse
  Documentation:
  https://zaragozamakerspace.com/index.php/courses/curso-basico-arduino/
  
  by Zaragoza Maker Space
*/


char serialData;

void setup() {
  Serial.begin(9600);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);

  serialData = (char)(('0'));
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);

}

void loop() {
  if (Serial.available()) {
    serialData = (Serial.read());
    if (serialData == ('A')) {
      digitalWrite(5, HIGH);
      digitalWrite(6, LOW);
    }
    if (serialData == ('D')) {
      digitalWrite(5, LOW);
      digitalWrite(6, HIGH);
    }
    if (serialData == ('S')) {
      digitalWrite(5, LOW);
      digitalWrite(6, LOW);
    }
    if (serialData == ('W')) {
      digitalWrite(5, HIGH);
      digitalWrite(6, HIGH);
    }
  }

}


