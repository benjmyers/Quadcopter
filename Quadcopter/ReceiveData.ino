

// Variables for input from xBee
String st, msgChar, msgInt, xAccel, yAccel, zAccel, zButton, cButton,newline; 
String yPlace, zPlace, zbPlace, cPlace;
// Variables for nunchuck values
int xVal, yVal, zVal, zBval, cBval;

String inData[5];
byte index = 0;
int input = 0;



void cleary(){
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
         index = 0;
     }
     else if (input == ' '){
       inData[index] = st;
       st = "";
       index++;
     }
     else{
       st+=input;
     }

  }
}

void printInput() {
   // 2 X 16
   lcd.setCursor(3,0);
   lcd.print(inData[0]);
   lcd.setCursor(8,0);
   lcd.print(inData[1]);
   lcd.setCursor(12,0);
   lcd.print(inData[2]);
   lcd.setCursor(3,1);
   lcd.print(inData[3]);
   lcd.setCursor(8,1);
   lcd.print(inData[4]);
   
   delay(25);
 
   lcd.clear();
 } 



