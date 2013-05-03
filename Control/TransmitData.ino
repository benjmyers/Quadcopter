/*
  XBeeMessage
 Send a message to an XBee using its address
 This is from the Arduino Cookbook, V2, Margolis
 */

void sendData(){
  Serial.print(disarmButton);
  Serial.print(" ");
  Serial.print(armButton);
  Serial.print(" ");
  Serial.print(yawControl);
  Serial.print(" ");
  Serial.print(throttleControl);
  Serial.print(" ");
  Serial.print(rollControl);
  Serial.print(" ");
  Serial.print(pitchControl); 
  //Serial.print(" ");
  Serial.print("\n");
}



