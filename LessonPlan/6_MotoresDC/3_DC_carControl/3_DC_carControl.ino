/*
  Free open Arduino Course

  Github:
  https://github.com/ZGZMakerSpace/ArduinoCourse
  Documentation:
  https://zaragozamakerspace.com/index.php/courses/curso-basico-arduino/
  
  by Zaragoza Maker Space
*/

char serialData;
int value;
int vel;
int M11=5;
int M12=6;
int M21=9;
int M22=10;

void move(int S11, int S12, int S21, int S22){
  analogWrite(M11,S11);
  analogWrite(M12,S12);
  analogWrite(M21,S21);
  analogWrite(M22,S22);
}

// Describe this function...
void stop() {
  move(0, 0, 0, 0);
}

// Describe this function...
void forward(int vel) {
  move(0, vel, vel, 0);
}

// Describe this function...
void backward(int vel) {
  move(vel, 0, 0, vel);
}

// Describe this function...
void left(int vel) {
  move(vel, 0, vel, 0);
}

// Describe this function...
void right(int vel) {
  move(0, vel, 0, vel);
}


void setup() {
  Serial.begin(9600);
    pinMode(M11,OUTPUT);
  pinMode(M12,OUTPUT);
  pinMode(M21,OUTPUT);
  pinMode(M22,OUTPUT);


  serialData = (char)(('0'));

}

void loop() {
  if (Serial.available()) {
    serialData = (Serial.read());
    if (serialData == ('W')) {
      value = (int)(((Serial.readString()).toInt()));
      forward(value);
      Serial.print("Forward: ");
    }
    if (serialData == ('S')) {
      value = (int)(((Serial.readString()).toInt()));
      backward(value);
      Serial.print("Backward: ");
    }
    if (serialData == ('A')) {
      value = (int)(((Serial.readString()).toInt()));
      left(value);
      Serial.print("Left: ");
    }
    if (serialData == ('D')) {
      value = (int)(((Serial.readString()).toInt()));
      right(value);
      Serial.print("Right: ");
    }
    if (serialData == ('Q')) {
      stop();
      Serial.print("Stop");
    }
    Serial.println(value);
  }

}



