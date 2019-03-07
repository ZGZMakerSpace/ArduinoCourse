/*
  Free open Arduino Course

  Github:
  https://github.com/ZGZMakerSpace/ArduinoCourse
  Documentation:
  https://zaragozamakerspace.com/index.php/courses/curso-basico-arduino/
  
  by Zaragoza Maker Space
*/

#include <Servo.h>
#include <Oscillator.h>

const unsigned char CMD_STOP = 'S';  //-- Stop the oscilaltor
const unsigned char CMD_PLAY = 'P';  //-- Play the oscillator

Oscillator osc;

void setup()
{
  //-- Configure the serial comunication with PC
  Serial.begin(9600);

  //-- Attach the oscillator to servo
  osc.attach(11);
  osc.SetT(1000);
  osc.SetA(40);
  osc.SetO(40);
  

}

//-- Incoming byte from the PC
unsigned char inbyte;

void loop()
{
  //-- refresh the oscillator
  osc.refresh();

  //-- When a byte is received from the PC
  if (Serial.available()) {

    //-- Read the byte and modify the oscillator state
    //-- acording to the command received
    inbyte = Serial.read();
    switch(inbyte){
      case CMD_STOP:     //-- Stop command
        osc.Stop();
        break;
      case CMD_PLAY:     //-- Play command
        osc.Play();
        break;
    }
  }
}
