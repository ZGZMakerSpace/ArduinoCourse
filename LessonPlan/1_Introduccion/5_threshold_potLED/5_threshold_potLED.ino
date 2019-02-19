/*
  Free open Arduino Course

  Github:
  https://github.com/ZGZMakerSpace/ArduinoCourse
  Documentation:
  https://zaragozamakerspace.com/index.php/courses/curso-basico-arduino/
  
  by Zaragoza Maker Space
*/

int LED;
int pot;
int threshold;
int val;

void setup() {
  Serial.begin(9600);
  pinMode(pot, INPUT);
  pinMode(LED, OUTPUT);

  LED = (int)(3);
  pot = (int)(0);
  threshold = (int)(450);

}

void loop() {
  val = (analogRead(pot));
  Serial.println(val);
  if (val > threshold) {
    digitalWrite(LED, HIGH);
  } else {
    digitalWrite(LED, LOW);
  }

}
