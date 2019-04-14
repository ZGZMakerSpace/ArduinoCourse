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

LiquidCrystal_I2C lcd(0x3f,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display

void setup()
{
  lcd.init();                      
  lcd.backlight();
  Serial.begin(9600);
  Serial.setTimeout(300);
}

void loop()
{
  if (Serial.available()) {
    String text = Serial.readString();

    lcd.clear();
    lcd.print( text );

  }
}
