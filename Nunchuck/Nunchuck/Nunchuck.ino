/*
*WiichuckSerial
*
*Uses Nunchuck Lib from 16.5
*sends comma-separated values for data
*Label string separated by commas can be used by receiving program
*to id fields
*/

#include <Wire.h>
#include "Nunchuck.h"

//value to add to the sensor to get zero reading when centered
int offsetX, offsetY, offsetZ;

void setup()
{
  Serial.begin(57600);
  //nunchuckSetPowerPins();
  nunchuckInit(); //send the init handshake

  nunchuckRead(); //ignore first tiem

  delay(50);
}

void loop()
{
  nunchuckRead();
  delay(6);
  nunchuckRequest();
  boolean btnC = nunchuckGetValue(wii_btnC);
  boolean btnZ = nunchuckGetValue(wii_btnZ);
  
  if(btnC) {
    offsetX = 127 - nunchuckGetValue(wii_accelX);
    offsetY = 127 - nunchuckGetValue(wii_accelY);
  }
  Serial.print("Data,");
  printAccel(nunchuckGetValue(wii_joyX));
  printAccel(nunchuckGetValue(wii_joyY));
  printButton(nunchuckGetValue(wii_btnZ));
  printButton(nunchuckGetValue(wii_btnC)); 
  Serial.println();
}

void printAccel(int value, int offset)
{
  Serial.print(adjReading(value, 127-50, 127+50, offset));
  Serial.print(",");
}
void printAnalogButton(int pinNo){
  int value = digitalRead(pinNo);
  delay(10);
  if ( value == 0){
    value = 127;
  }
  else{
   value = 0; 
  }
  Serial.print(value,DEC);
  Serial.print(",");
}
void printJoy(int value)
{
  Serial.print(adjReading(value,0, 255, 0));
  Serial.print(",");
}

void printButton(int value)
{
  if ( value != 0){
    value = 127;
  }
  Serial.print(value,DEC);
  Serial.print(",");
}

int adjReading( int value, int min, int max, int offset)
{
  value = constrain(value + offset, min, max);
  value = map(value, min, max, -127, 127);
  return value;
}

