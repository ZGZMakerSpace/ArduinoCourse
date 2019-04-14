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

int LCD_COLS = 16;
int LCD_ROWS = 2;
LiquidCrystal_I2C lcd(0x3f,LCD_COLS,LCD_ROWS);  

unsigned long scrolltimer;
unsigned long auxtimer;
int delayTime = 500;
int space = 4;
int totalscroll = 40;
boolean auxvar = true;

void setup()
{
  Serial.begin(9600);
  lcd.init();                      
  lcd.backlight();
  pinMode(3,INPUT);
  randomSeed( analogRead(0) );
  Serial.println( ( totalscroll )/space - 2);
  for (int i=0; i < ( totalscroll)/space -2; i++ ){
    
    int col = LCD_COLS+ space*i;
    int row = random(0, 2);
    Serial.println( (String)row + " - "+(String)col );
    lcd.setCursor( col, row );
    lcd.write( 255  );
  }

}

void loop()
{

  if( millis() - scrolltimer > delayTime){
    scrolltimer = millis();
    lcd.scrollDisplayLeft();
    Serial.println(millis());
  };

  if( millis() > delayTime*(totalscroll-LCD_COLS) && auxvar){
      auxvar = false;
      for (int i=0; i < ( LCD_COLS )/space -1; i++ ){
    
        int col = space*i;
        int row = random(0, 2);
        Serial.println( (String)row + " - "+(String)col );
        lcd.setCursor( col, row );
        lcd.write( 255  );
      }
  
  };
  /*if( millis() - auxtimer > space*delayTime){
    auxtimer = millis();
    float rnd = random(0, 2);
    Serial.print("RND: ");Serial.print(rnd);
    lcd.setCursor( 16, rnd);
    
    lcd.write( 255  );
    Serial.print( " Obstacle ");
    Serial.println(millis());
  };*/

}
