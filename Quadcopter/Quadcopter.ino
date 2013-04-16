/*Test Comment */
int nunchuckData[5];

void setup()
{
  Serial.begin(9600); // 9600 for xBee
}

void loop()
{ 
  // Get data from Wiimote
  
  parseXbeeData();
  // Get data from accelerometer and gyro https://github.com/jrowberg/i2cdevlib
  // https://www.sparkfun.com/products/11028
  
  // Adjust motor speeds 

  
}
