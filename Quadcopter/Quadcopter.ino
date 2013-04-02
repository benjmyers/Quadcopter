
int nunchuckData[5];

void setup()
{
  Serial.begin(9600); // 9600 for xBee
}

void loop()
{ 
  // Get data from Wiimote
  getData();
  // Get data from accelerometer and gyro
  
  // Adjust motor speeds

  
}
