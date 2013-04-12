/*
  XBeeEcho
 Reply with whatever you receive over the serial port
 From Arduino Cookbook, V2, Margolis
 */

void getData(){
  String data;
  while (Serial.available() ) 
    data += Serial.read(); // Read in data
   
  // Parse Data
  
}  
    
