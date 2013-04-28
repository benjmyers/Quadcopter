//value to add to the sensor to get zero reading when centered
int offsetX, offsetY, offsetZ;

void readNunchuck(){
  
  nunchuckRead();
  delay(6);
  nunchuckRequest();
  boolean btnC = nunchuckGetValue(wii_btnC);
  boolean btnZ = nunchuckGetValue(wii_btnZ);
  
  if(btnC) {
    offsetX = 127 - nunchuckGetValue(wii_accelX);
    offsetY = 127 - nunchuckGetValue(wii_accelY);
  }
  int xAccel = nunchuckGetValue(wii_joyX);
  printJoy(xAccel,0);
  int yAccel = nunchuckGetValue(wii_joyY);
  printJoy(yAccel,1);
  
  int zButton = nunchuckGetValue(wii_btnZ);
  printButton(zButton,2);
  int cButton = nunchuckGetValue(wii_btnC); 
  printButton(cButton,3);
  Serial.println('\n');
}

//------------------------------------------------------------
//------------------ Printing nunchuck data ------------------
//------------------------------------------------------------

void printAccel(int value, int offset, int index)
{
  nunchuckData[index] = adjReading(value, 127-50, 127+50, offset);

  /*Serial.print(adjReading(value, 127-50, 127+50, offset));
  Serial.print(", ");*/
}
void printButton(int value, int index)
{
  if ( value != 0){
    value = 1;
  }
  nunchuckData[index] = value;
  Serial.print(value,DEC);
  Serial.print(" ");
}

void printJoy(int value, int index)
{
  Serial.print(adjReading(value,0, 255, 0));
  Serial.print(" ");
}

int adjReading( int value, int min, int max, int offset)
{
  value = constrain(value + offset, min, max);
  value = map(value, min, max, -127, 127);
  return value;
}

