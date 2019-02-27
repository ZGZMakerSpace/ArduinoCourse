/*
  Free open Arduino Course

  Github:
  https://github.com/ZGZMakerSpace/ArduinoCourse
  Documentation:
  https://zaragozamakerspace.com/index.php/courses/curso-basico-arduino/
  
  by Zaragoza Maker Space
*/

volatile bool stop = false; 

void isr_stop(){
   Serial.println(" Loop OFF ");
   stop = true;
};

void isr_reset(){
   Serial.println(" Loop ON");
   stop = false;
};

void setup() {
  Serial.begin(9600);
  pinMode(buttonRESET, INPUT);
  attachInterrupt(digitalPinToInterrupt(2),isr_stop, RISING);
  attachInterrupt(digitalPinToInterrupt(3),isr_reset, RISING);

}

void loop() {
  if (stop){
    for (int i = 1; i <= 1000; i++) {
      Serial.println(i);
      if (stop){
        break;
      }
    }
  }
}


