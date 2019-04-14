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
int pos = 2;

void setup()
{
  Serial.begin(9600);
  lcd.init();                      
  lcd.backlight();
  pinMode(3,INPUT);

}

void loop()
{
  Serial.println( digitalRead(3) );
  if(digitalRead(3) != flag){
    flag = digitalRead(3);
    if ( flag == true){
      lcd.setCursor(pos,1);
      lcd.write( 32 );
      lcd.setCursor(pos,0);
      lcd.write( 126 );
    }
    if ( flag == false){
      lcd.setCursor(pos,0);
      lcd.write( 32 );
      lcd.setCursor(pos,1);
      lcd.write( 126 );
    }
    
  }

}
