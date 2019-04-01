volatile int rune = 0;
int nrunes=40;
int oldrune = 0;

void doEncoder(){
  rune++;
}

void setup(){
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(2), doEncoder, CHANGE);
}
void loop(){
  if (oldrune != rune ){
    Serial.println(rune);
    oldrune == rune ;
  }
  
}
