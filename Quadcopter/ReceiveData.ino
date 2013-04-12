/*
  XBeeEcho
 Reply with whatever you receive over the serial port
 From Arduino Cookbook, V2, Margolis
 */
String st, msgChar, msgInt, xAccel, yAccel, zAccel, zButton, cButton,newline 

void getData(){
  if(st.indexOf("\n")>=0)
  {
    newline=st.substring(0,(st.indexOf("\n")));
    
  }
  
      
   
  // Parse Data
    
}  

void loop(){
  if(Serial.available())
  {
    st = String("");
    while(Serial.available())
    {
      st = st + char(Serial.read());
    }
    
    getData()
   if(newline.indexOf(" ")>0)
    {
      xAccel = newline.substring(0,(newline.indexOf(" ")));
      newline = newline.substring(newline.indexOf(" ")+1);
      xAccel = (xAccel.toInt());
    }
    if(newline.indexOf(" ")>0)
    {
     yAccel = newline.substring(0,(newline.indexOf(" ")));
     newline = newline.substring(newline.indexOf(" ")+1);
     yAccel = (yAccel.toInt());
    }
   
   if(newline.indexOf(" ") > 0)
   {
     zAccel = newline.substring(0,(newline.indexOf(" ")));
     newline = newline.substring(newline.indexOf(" ")+1);
     zAccel = (zAccel.toInt());
   }
   
   if(newline.indexOf(" ") > 0)
   {
     zButton = newline.substring(0,(newline.indexOf(" ")));
     newline= newline.substring(newline.indexOf(" ")+1);
     zButton = (zButton.toInt())
   }
   
   if(newline.indexOf(" ")>0)
   {
     cButton = newline.substring(0, (newline.indexOf(" ")));
     newline=newline.substring(newline.indexOf(" ")+1);
     cButton = (cButton.toInt())
     
   }
  }
   Serial.print("X Accel= " + xAccel + "Y Accel= " + yAccel+ "Z Accel= " +zAccel);
   Serial.println("ZButton= " + zButton + "CButton= " + cButton);

}
  
      
      
