

#include <Servo.h>

int motorPin1;
int motorPin2;
int motorPin3;
int motorPin4;
long time;
int i;

Servo motor1;
Servo motor2;
Servo motor3;
Servo motor4;

void setup() {
  Serial.begin(9600);

  motorPin1 = (int)(5);
  motorPin2 = (int)(9);
  motorPin3 = (int)(10);
  motorPin4 = (int)(11);
  motor1.attach(motorPin1);
  motor2.attach(motorPin1);
  motor3.attach(motorPin1);
  motor4.attach(motorPin1);
  time = (long)(0);

}

void loop() {
  time = millis();
  for (i = 0; i <= 180; i++) {
    motor1.write(i);
    delay(10);
  }
  for (i = 180; i >= 0; i--) {
    motor1.write(i);
    delay(10);
  }


  Serial.println((millis() - time));

}


