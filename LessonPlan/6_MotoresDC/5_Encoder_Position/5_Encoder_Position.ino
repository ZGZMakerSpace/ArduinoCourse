

int rune;
boolean runestate;
int nrune;
int turns;
boolean turnstate;

void setup() {
  Serial.begin(9600);
  pinMode(2, INPUT);

  rune = (int)(0);
  runestate = (boolean)(false);
  nrune = (int)(40);
  turns = (int)(0);
  turnstate = (boolean)(false);

}

void loop() {
  if(digitalRead(2) != runestate){
    runestate = digitalRead(2);
      rune = rune + 1;
    Serial.println(rune);
    turns = rune / nrune;

  }if(turns != turnstate){
    turnstate = turns;
      Serial.println((String("Turns: ") + String(turns)));

  }
}



