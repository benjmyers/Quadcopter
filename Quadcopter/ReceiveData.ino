/*
  XBeeEcho
 Reply with whatever you receive over the serial port
 From Arduino Cookbook, V2, Margolis
 */
String st, msgChar, msgInt, xAccel, yAccel, zAccel, zButton, cButton,newline; 
int xVal, yVal, zVal, zBval, cBval;

/* Parses data from Xbee (Nunchuck values) */
void parseXbeeData(){
  if(Serial.available())
  {
    newline = String("");
    while(Serial.read() != '\n')
    {
      newline = newline + char(Serial.read());
    }
    
   if(newline.indexOf(" ")>0)
    {
      xAccel = newline.substring(0,(newline.indexOf(" ")));
      newline = newline.substring(newline.indexOf(" ")+1);
      xVal = (xAccel.toInt());
      nunchuckData[0] = xVal;
    }
    if(newline.indexOf(" ")>0)
    {
     yAccel = newline.substring(0,(newline.indexOf(" ")));
     newline = newline.substring(newline.indexOf(" ")+1);
     yVal = (yAccel.toInt());
     nunchuckData[1] = yVal;
    }
   
   if(newline.indexOf(" ") > 0)
   {
     zAccel = newline.substring(0,(newline.indexOf(" ")));
     newline = newline.substring(newline.indexOf(" ")+1);
     zVal = (zAccel.toInt());
     nunchuckData[2] = zVal;
   }
   
   if(newline.indexOf(" ") > 0)
   {
     zButton = newline.substring(0,(newline.indexOf(" ")));
     newline= newline.substring(newline.indexOf(" ")+1);
     zBval = (zButton.toInt());
     nunchuckData[3] = zBval;
   }
   
   if(newline.indexOf(" ")>0)
   {
     cButton = newline.substring(0, (newline.indexOf(" ")));
     newline=newline.substring(newline.indexOf(" ")+1);
     cBval = (cButton.toInt());
     nunchuckData[4] = cBval;
     
   }
  }
   Serial.print("X Accel= ");
   Serial.print(xVal);
   Serial.print(" Y Accel= ");
   Serial.print(yVal);
   Serial.print(" Z Accel= ");
   Serial.print(zVal);
   Serial.print(" ZButton= ");
   Serial.print(zBval);
   Serial.print(" CButton= ");
   Serial.println(cBval);
  

}
  
      
      
