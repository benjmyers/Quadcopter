

// Variables for input from xBee
String st, msgChar, msgInt, xAccel, yAccel, zAccel, zButton, cButton,newline; 
String yPlace, zPlace, zbPlace, cPlace;
// Variables for nunchuck values
int xVal, yVal, zVal, zBval, cBval;

char inData[40];
byte index = 0;
int input = 0;



/* Get acceleration and gyro */
/*void getMotion(){
     // read raw accel/gyro measurements from device
    accelgyro.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
}*/

/* Parses data from Xbee (Nunchuck values) */
void parseXbeeData(){
  
  int varCt = 0;
  st = "";
  while(Serial.available()){
      
      input = Serial.read();
      if(input != -1){
        char aChar = char(input);
      if(aChar == '\n'){ // end of the input line
        st = st + aChar;
        /*index = 0;
        varCt = 0;
        /* for (int i=0;i<40;i++){
            Serial.print(inData[i]); 
            inData[i] = 0;
         }
        
         lcd.setCursor(0,0);
         lcd.print(st); */
        Serial.println("About to be parsed"); 
        if(st.indexOf("n") != 1) {
          Serial.println("Parsing has begun");
          if(st.indexOf(" ") > 0){
            xAccel = st.substring(0, (st.indexOf(" ")));
            yPlace = st.substring((st.indexOf(" "))+1);
            lcd.setCursor(0,0);
            lcd.print("x");
            lcd.print(xAccel);
            
          }
          if(yPlace.indexOf(" ") > 0){
            yAccel = st.substring(0, (st.indexOf(" ")));
            zPlace = yPlace.substring((yPlace.indexOf(" ")) + 1);
            lcd.setCursor(5,0);
            lcd.print("y");
            lcd.print(yAccel);
            
          }
          if(zPlace.indexOf(" ") > 0){
            zAccel = st.substring(0, (st.indexOf(" ")));
            zbPlace = zPlace.substring((zPlace.indexOf(" "))+1);
           lcd.setCursor(10,0);
            lcd.print("z");
            lcd.print(zAccel);
            
          }
          if(zbPlace.indexOf(" ") > 0){
            zButton = st.substring(0, (st.indexOf(" ")));
            cPlace = zbPlace.substring((zbPlace.indexOf(" ")) + 1);
            lcd.setCursor(0,1);
            lcd.print("zb");
            lcd.print(zButton);
            
          }
         if(cPlace.indexOf(" ") > 0){
           cButton = st.substring(0, (st.indexOf(" ")));
           st = cPlace.substring((cPlace.indexOf(" ")) +1);
            lcd.setCursor(7,1);
            lcd.print("cb");
            lcd.print(cButton);
            
         
      }Serial.println("parsed");
       delay(1000);
       lcd.clear();
       }
      
      
      
      
     
      
      }
      
      else{
        /* inData[index] = aChar;
         index++;
         inData[index] = ':'; // Keep the string NULL terminated*/ 
         st = st + aChar;
      }
     
      
   }
}

}
  
      
  
  


/*void parse(int varCt) {
  int index = 0;
  String num = "";
  while(inData[index] != ':'){
      num = num + inData[index];
      
  }
  nunchuckData[varCt] = num.toInt();
  // 2 X 16
  lcd.setCursor(0,0);
  lcd.print("x "+nunchuckData[0]);
  lcd.setCursor(5,0);
  lcd.print("y "+nunchuckData[1]);
  lcd.setCursor(10,0);
  lcd.print("z "+nunchuckData[2]);
  lcd.setCursor(0,1);
  lcd.print("zb "+nunchuckData[3]);
  lcd.setCursor(5,1);
  lcd.print("cb "+nunchuckData[4]);
  
} */
  
      
      
