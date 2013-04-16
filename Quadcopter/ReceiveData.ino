/*
  XBeeEcho
 Reply with whatever you receive over the serial port
 From Arduino Cookbook, V2, Margolis
 */
String st, msgChar, msgInt, xAccel, yAccel, zAccel, zButton, cButton,newline; 
int xVal, yVal, zVal, zBval, cBval;
void getData(){
  if(st.indexOf("\n")>=0)
  {
    newline=st.substring(0,(st.indexOf("\n")));
    
  }
  
      
   
  // Parse Data
    
}  

void stringLoop(){
  if(Serial.available())
  {
    st = String("");
    while(Serial.available())
    {
      st = st + char(Serial.read());
    }
    
   getData();
   if(newline.indexOf(" ")>0)
    {
      xAccel = newline.substring(0,(newline.indexOf(" ")));
      newline = newline.substring(newline.indexOf(" ")+1);
      xVal = (xAccel.toInt());
    }
    if(newline.indexOf(" ")>0)
    {
     yAccel = newline.substring(0,(newline.indexOf(" ")));
     newline = newline.substring(newline.indexOf(" ")+1);
     yVal = (yAccel.toInt());
    }
   
   if(newline.indexOf(" ") > 0)
   {
     zAccel = newline.substring(0,(newline.indexOf(" ")));
     newline = newline.substring(newline.indexOf(" ")+1);
     zVal = (zAccel.toInt());
   }
   
   if(newline.indexOf(" ") > 0)
   {
     zButton = newline.substring(0,(newline.indexOf(" ")));
     newline= newline.substring(newline.indexOf(" ")+1);
     zBval = (zButton.toInt());
   }
   
   if(newline.indexOf(" ")>0)
   {
     cButton = newline.substring(0, (newline.indexOf(" ")));
     newline=newline.substring(newline.indexOf(" ")+1);
     cBval = (cButton.toInt());
     
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
  
      
      
