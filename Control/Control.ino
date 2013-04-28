

#include <Wire.h>
#include "Nunchuck.h"

int nunchuckData[4];
boolean radioConfigured;
int sendCt = 0;

void setup()
{
  Serial.begin(9600); // 9600 for xBee, 57600 for printing from wii mote
  
  // ----- Set up Nunchuck -----
  nunchuckInit(); //send the init handshake
  nunchuckRead(); //ignore first tiem

  
  delay(50);
}

void loop()
{ 
  readNunchuck();  // This will put all the nunchuck values into nunchuckData[]
  if(sendCt % 50 == 0){
    sendData();
    sendCt = 0;
  }
  sendCt++;
}







