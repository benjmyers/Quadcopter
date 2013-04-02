

#include <Wire.h>
#include "Nunchuck.h"

int nunchuckData[5];
boolean radioConfigured;

void setup()
{
  Serial.begin(9600); // 9600 for xBee, 57600 for printing from wii mote
  
  // ----- Set up Nunchuck -----
  nunchuckInit(); //send the init handshake
  nunchuckRead(); //ignore first tiem
  // ----- Set up Radio -----
  radioConfigured = configureRadio();
  
  delay(50);
}

void loop()
{ 
  readNunchuck();  // This will put all the nunchuck values into nunchuckData[]
  sendData();

}







