/*
  Free open Arduino Course

  Github:
  https://github.com/ZGZMakerSpace/ArduinoCourse
  Documentation:
  https://zaragozamakerspace.com/index.php/courses/curso-basico-arduino/
  
  by Zaragoza Maker Space
*/
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3f,16,2);  

unsigned long auxtimer;
int flag = true;
int timecounter = 0;
int btncounter = 0;

void setup()
{
  Serial.begin(9600);
  lcd.init();                      
  lcd.backlight();
  pinMode(4,INPUT);
}

void loop()
{
  Serial.println( digitalRead(4) );
  if(digitalRead(4) != flag){
    flag = digitalRead(4);
    btncounter++;
    Serial.println(btncounter);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print( btncounter );
  }

  if( millis() - auxtimer > 1000){
    auxtimer = millis();
    timecounter++;
    lcd.setCursor(5,1);
    lcd.print( timecounter );
  };
}
