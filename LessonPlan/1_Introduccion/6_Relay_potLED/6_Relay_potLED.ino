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
int threshold_L;
int threshold_H;
boolean state;
int val;

void setup() {
  Serial.begin(9600);
  pinMode(pot, INPUT);
  pinMode(LED, OUTPUT);

  LED = (int)(3);
  pot = (int)(0);
  threshold_L = (int)(450);
  threshold_H = (int)(800);
  state = (boolean)(false);
  if ((analogRead(pot)) > threshold_L) {
    state = true;
  } else if ((analogRead(pot)) < threshold_H) {
    state = false;
  }

}

void loop() {
  val = (analogRead(pot));
  Serial.println(val);
  if (state == false && val > threshold_H) {
    state = true;
    digitalWrite(LED, HIGH);
  } else if (state == true && val < threshold_L) {
    state = false;
    digitalWrite(LED, LOW);
  }

}


