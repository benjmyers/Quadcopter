  #include <Servo.h> 
  #include <Wire.h>
  #include "Nunchuck.h"
  
  Servo throttle;
  Servo roll;
  Servo pitch;
  Servo yaw;
  int ch_1_val, ch_2_val, ch_3_val, ch_4_val;
  int MIN = 1000;
  int MAX = 1990;
  const int switch_1 = 3;
  const int switch_2 = 4;
  boolean disarmButton, armButton;
  int yawControl, throttleControl, rollControl, pitchControl;
  
  void setup(){
    Serial.begin(9600);
    
    throttle.attach(8);
    roll.attach(9);
    pitch.attach(10);
    yaw.attach(11); 
    
//    pinMode(switch_1, INPUT);
//    pinMode(switch_2, INPUT);
    
    // ----- Set up Nunchuck -----
    nunchuckInit(); //send the init handshake
    nunchuckRead(); //ignore first time
    
    
  }
  
  void loop(){
    
   readNunchuck();
   
   if(armButton){
     Serial.println("arm");
        arm();
   }
   else if(disarmButton){
     Serial.println("Disarm");
      disarm(); 
   }
   else{
     // t r p y
      dispatch(throttleControl, rollControl, pitchControl, yawControl);
      printValues();
     
   } 
    
  }
  
  void arm(){
    // Initial arming values
    dispatch(MIN-11,MAX+11,1500,1500);
    // Wait awhile
    delay(3000);
    // Secondary arming values
    dispatch(MIN-11,1500,1500,MAX+11);
    // Wait
    delay(1000);
    
    
  }
  
  void disarm(){
    dispatch(MIN-11,MIN-11,1500,1500);
    delay(3000);
    dispatch(MIN-11,1500,1500,MIN-11);
    delay(1000);
    
  }
  
  void dispatch(int t, int r, int p, int y){
    throttle.writeMicroseconds(t);
    roll.writeMicroseconds(r);
    pitch.writeMicroseconds(p);
    yaw.writeMicroseconds(y);
    
  }
  
  int scaleAccel(int input){
    float mul = input * 3.94;
    int output = ((int)mul) + 1500;
    return output;
  }
 int scaleJoy(int input){
    float mul = input * 5;
    int output = ((int)mul) + 1500;
    return output;
  }
  
  void readNunchuck(){
  
  nunchuckRead();
  delay(6);
  nunchuckRequest();
  
  disarmButton = nunchuckGetValue(wii_btnZ);
  armButton = nunchuckGetValue(wii_btnC);
  
  yawControl = adjReading(nunchuckGetValue(wii_joyX),0, 255);
  throttleControl = adjReading(nunchuckGetValue(wii_joyY),0, 255);
  
  rollControl = adjReading(nunchuckGetValue(wii_accelX), 0, 255);
  pitchControl = adjReading(nunchuckGetValue(wii_accelY), 0, 255);
  

}

void printValues(){
   Serial.print(disarmButton);Serial.print(" ");
  Serial.print(armButton);Serial.print(" ");
  Serial.print(yawControl);Serial.print(" ");
  Serial.print(throttleControl);Serial.print(" ");
  Serial.print(rollControl);Serial.print(" ");
  Serial.println(pitchControl); 
}
int adjReading(int value, int min, int max)
{
  value = constrain(value, min, max);
  value = map(value, min, max, 1000, 1990);
  return value;
}

