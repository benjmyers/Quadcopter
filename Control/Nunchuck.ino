//value to add to the sensor to get zero reading when centered
int offsetX, offsetY, offsetZ;
boolean disarmButton, armButton;
int yawControl, throttleControl, rollControl, pitchControl;

void readNunchuck(){

  nunchuckRead();
  delay(6);
  nunchuckRequest();

  disarmButton = nunchuckGetValue(wii_btnZ);
  armButton = nunchuckGetValue(wii_btnC);

  yawControl = adjReading(nunchuckGetValue(wii_joyX),0, 255);
  throttleControl = adjReading(nunchuckGetValue(wii_joyY),0, 255);

  rollControl = adjReading(nunchuckGetValue(wii_accelX), 0, 255);
  pitchControl = adjReading(nunchuckGetValue(wii_accelY), 0, 255);


}


//------------------------------------------------------------
//------------------ Printing nunchuck data ------------------
//------------------------------------------------------------



int adjReading(int value, int min, int max)
{
  value = constrain(value, min, max);
  value = map(value, min, max, 1000, 1990);
  return value;
}

