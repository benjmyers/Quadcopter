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



void setup()
{
  Serial.begin(57600);
  // ----- Set up Nunchuck -----

  nunchuckInit(); //send the init handshake
  nunchuckRead(); //ignore first tiem

  delay(50);
}

void loop()
{
  readNunchuck();
}







