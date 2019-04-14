/*
  Free open Arduino Course

  Github:
  https://github.com/ZGZMakerSpace/ArduinoCourse
  Documentation:
  https://zaragozamakerspace.com/index.php/courses/curso-basico-arduino/
  
  by Zaragoza Maker Space
*/
#include <Wire.h>
#include <LiquidCrystal_I2C.h>//F. Malpartida LCD's driver

LiquidCrystal_I2C lcd(0x3f,16,2);

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.setCursor(1,0);
  lcd.print("Arduino Course");
  lcd.setCursor(1,1);
  lcd.print("ZGZ MakerSpace");
}

void loop() {
  // put your main code here, to run repeatedly:

}
