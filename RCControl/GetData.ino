//boolean disarmButton, armButton;
//int yawControl, throttleControl, rollControl, pitchControl;

/* Parses data from Xbee (Nunchuck values) */
void parseXbeeData(){
  String inData[6];
  byte index = 0;
  int input = 0;
  int varCt = 0;
  String st = "";

  while(Serial.available()){
    delay(3);
    char input = char(Serial.read());
    if(input == '\n'){
      st = "";
      index = 0;
      disarmButton =     inData[0].toInt();
      armButton =       inData[1].toInt();
      yawControl =       inData[2].toInt();
      throttleControl = inData[3].toInt();
      rollControl = inData[4].toInt();
      pitchControl = inData[5].toInt();
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


void printData(){
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
  Serial.print("\n");
}


