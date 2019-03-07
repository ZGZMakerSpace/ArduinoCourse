/*
  Free open Arduino Course

  Github:
  https://github.com/ZGZMakerSpace/ArduinoCourse
  Documentation:
  https://zaragozamakerspace.com/index.php/courses/curso-basico-arduino/
  
  by Zaragoza Maker Space
*/


int A;
int T;
int O;
int position;

void setup() {
  Serial.begin(9600);

  A = (int)(100);
  T = (int)(1000);
  O = (int)(0);
  position = (int)(0);

}

void loop() {
  position = A * sin((((2 * M_PI) / T) * millis()) );
  Serial.println(position);

}


