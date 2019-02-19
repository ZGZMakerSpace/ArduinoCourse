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
int time;
int val;

void setup() {
  Serial.begin(9600);
  pinMode(pot, INPUT);
  pinMode(LED, OUTPUT);

  LED = (int)(3);
  pot = (int)(0);
  threshold = (int)(800);
  time = (int)(0);

}

void loop() {
  val = (analogRead(pot));
  time = (map(LED, 0, 1024, 0, 3000));
  if (val > threshold) {
    time = 3000;
  }
  digitalWrite(LED, HIGH);
  delay(time);
  digitalWrite(LED, LOW);
  delay(time);

}


