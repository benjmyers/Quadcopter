

// Variables for input from xBee
String st, msgChar, msgInt, xAccel, yAccel, zAccel, zButton, cButton,newline; 
// Variables for nunchuck values
int xVal, yVal, zVal, zBval, cBval;

char inData[40];
byte index = 0;


/* Get acceleration and gyro */
void getMotion(){
     // read raw accel/gyro measurements from device
    accelgyro.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
    Serial.println(ax);
}

/* Parses data from Xbee (Nunchuck values) */
void parseXbeeData(){
  int varCt = 0;
  st = "";
  while(Serial.available() > 0){

      char aChar = Serial.read();
      if(aChar == '\n'){ // end of the input line
         index = 0;
         varCt = 0;
         inData[index] = ':';
         for (int i=0;i<40;i++){
            Serial.print(inData[i]); 
         }
         Serial.println('\n');
      }
      
      else if(aChar == ' '){  // end of a int

        // parse(varCt);
         varCt++;
      }
      else{
         inData[index] = aChar;
         index++;
         inData[index] = ':'; // Keep the string NULL terminated
      }
   }
}
void parse(int varCt) {
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
  
}
  
      
      
