

// Variables for input from xBee
String st, msgChar, msgInt, xAccel, yAccel, zAccel, zButton, cButton,newline; 
String yPlace, zPlace, zbPlace, cPlace;
// Variables for nunchuck values
int xVal, yVal, zVal, zBval, cBval;

String inData[5];
byte index = 0;
int input = 0;
int slow = 0;


/* Get acceleration and gyro */
/*void getMotion(){
 // read raw accel/gyro measurements from device
 accelgyro.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
 }*/
void clear(){
   for(int i=0;i<5;i++){
      inData[i] = "";
   } 
}
/* Parses data from Xbee (Nunchuck values) */
void parseXbeeData(){

  int varCt = 0;
  st = "";
  while(Serial.available()){
    
    char input = char(Serial.read());
     if(input == '\n'){
         st = "";
         //parse();
         clear();
         index = 0;
     }
     else if (input == ' '){
       inData[index] = st;
       lcd.print(st);
       st = "";
       index++;
     }
     else{
       st+=input;
     }

     slow++;
  }
}

void parse() {
   // 2 X 16
   lcd.setCursor(0,0);
   lcd.print("x "+inData[0]);
   lcd.setCursor(5,0);
   lcd.print("y "+inData[1]);
   lcd.setCursor(10,0);
   lcd.print("z "+inData[2]);
   lcd.setCursor(0,1);
   lcd.print("zb "+inData[3]);
   lcd.setCursor(5,1);
   lcd.print("cb "+inData[4]);
 
 } 
/*
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
          }
          Serial.println("parsed");
          delay(1000);
          lcd.clear();
        }*/


