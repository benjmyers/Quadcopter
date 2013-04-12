/*
  XBeeMessage
 Send a message to an XBee using its address
 This is from the Arduino Cookbook, V2, Margolis
 */

void sendData(){
  /* Data format:
  <xAccel> <yAccel> <zAccel> <zButton> <cButton> \n */
  for(int i=0;i<5;i++){
    Serial.print(nunchuckData[i]); 
    Serial.print(" ");
  }
  Serial.print("\n");
}



