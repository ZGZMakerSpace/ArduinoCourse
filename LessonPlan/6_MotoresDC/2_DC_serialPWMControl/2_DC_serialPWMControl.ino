/*
  Free open Arduino Course

  Github:
  https://github.com/ZGZMakerSpace/ArduinoCourse
  Documentation:
  https://zaragozamakerspace.com/index.php/courses/curso-basico-arduino/
  
  by Zaragoza Maker Space
*/



char serialData;
int pin1;
int pin2;
int value;

void setup() {
  Serial.begin(9600);
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);

  serialData = (char)(('0'));
  pin1 = (int)(5);
  pin2 = (int)(6);

}

void loop() {
  if (Serial.available()) {
    serialData = (Serial.read());
    if (serialData == ('A')) {
      value = (int)(((Serial.readString()).toInt()));
      analogWrite(pin1, value);
      analogWrite(pin2, 0);
      Serial.print("Forward: ");
      Serial.println(value);
    }
    if (serialData == ('D')) {
      value = (int)(((Serial.readString()).toInt()));
      analogWrite(pin1, 0);
      analogWrite(pin2, value);
      Serial.print("Backward: ");
      Serial.println(value);
    }
    if (serialData == ('S')) {
      digitalWrite(pin1, LOW);
      digitalWrite(pin2, LOW);
    }
    if (serialData == ('W')) {
      digitalWrite(pin1, HIGH);
      digitalWrite(pin2, HIGH);
    }
  }

}



