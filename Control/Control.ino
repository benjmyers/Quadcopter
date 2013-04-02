

#include <Wire.h>
#include "Nunchuck.h"

int nunchuckData[5];

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
  readNunchuck();  // This will put all the nunchuck values into nunchuckData[]
  Serial.println(nunchuckData[0]);
}







