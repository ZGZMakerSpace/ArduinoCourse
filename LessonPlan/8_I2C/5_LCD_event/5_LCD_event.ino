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

int flag = true;
int btncounter = 0;

void setup()
{
  Serial.begin(9600);
  lcd.init();                      
  lcd.backlight();
  pinMode(13,INPUT);
  lcd.setCursor(1,0);
  lcd.print("I2C ZMS ARDUINO");
  
}

void loop()
{
  Serial.println( digitalRead(13) );
  if(digitalRead(13) != flag){
    flag = digitalRead(13);
    if ( flag == false){
      btncounter++;
      Serial.println(btncounter);
      lcd.setCursor(7,1);
      lcd.print( btncounter );
    }
  }

}
