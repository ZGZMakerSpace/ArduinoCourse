/*
  Free open Arduino Course

  Github:
  https://github.com/ZGZMakerSpace/ArduinoCourse
  Documentation:
  https://zaragozamakerspace.com/index.php/courses/curso-basico-arduino/
  
  by Zaragoza Maker Space
*/
int LED_1;
int LED_2;
int LED_3;
int COIN_1;
int COIN_2;
int RESET;
int state_BTN1;
int state_BTN2;
int state_RESET;
int sum;
int status;

void LED_Status(int status) {
  if (status % 2 == 1) {
    digitalWrite(LED_1, HIGH);
  } else {
    digitalWrite(LED_1, LOW);
  }
  status = status / 2;
  if (status % 2 == 1) {
    digitalWrite(LED_2, HIGH);
  } else {
    digitalWrite(LED_2, LOW);
  }
  status = status / 2;
  if (status % 2 == 1) {
    digitalWrite(LED_3, HIGH);
  } else {
    digitalWrite(LED_3, LOW);
  }
  status = status / 2;
  if (status > 0) {
    digitalWrite(LED_1, LOW);
    digitalWrite(LED_2, LOW);
    digitalWrite(LED_3, LOW);
  }
}


void setup() {
  pinMode(COIN_1, INPUT);
  pinMode(COIN_2, INPUT);
  pinMode(RESET, INPUT);
  pinMode(LED_1, OUTPUT);
  pinMode(LED_2, OUTPUT);
  pinMode(LED_3, OUTPUT);

  LED_1 = (int)(9);
  LED_2 = (int)(10);
  LED_3 = (int)(11);
  COIN_1 = (int)(2);
  COIN_2 = (int)(3);
  RESET = (int)(4);
  state_BTN1 = (int)(0);
  state_BTN2 = (int)(0);
  state_RESET = (int)(0);
  sum = (int)(0);

}

void loop() {
  if(digitalRead(COIN_1) != state_BTN1){
    state_BTN1 = digitalRead(COIN_1);
      if (digitalRead(COIN_1) == true) {
      sum = sum + 1;
    }
    LED_Status(sum);

  }if(digitalRead(COIN_2) != state_BTN2){
    state_BTN2 = digitalRead(COIN_2);
      if (digitalRead(COIN_2) == true) {
      sum = sum + 2;
    }
    LED_Status(sum);

  }if(digitalRead(RESET) != state_RESET){
    state_RESET = digitalRead(RESET);
      sum = 0;
    digitalWrite(LED_1, LOW);
    digitalWrite(LED_2, LOW);
    digitalWrite(LED_3, LOW);

  }
}


