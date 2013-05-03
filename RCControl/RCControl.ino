#include <Servo.h> 
#include <Wire.h>
#include "Nunchuck.h"

Servo throttle;
Servo roll;
Servo pitch;
Servo yaw;
int MIN = 1000;
int MAX = 1990;
boolean disarmButton, armButton;
int yawControl, throttleControl, rollControl, pitchControl;

void setup(){
  Serial.begin(9600);

  throttle.attach(8);
  roll.attach(9);
  pitch.attach(10);
  yaw.attach(11); 

  // ----- Set up Nunchuck -----
  nunchuckInit(); //send the init handshake
  nunchuckRead(); //ignore first time


}

void loop(){
  // Get data from Wiimote
  parseXbeeData(); 
  printData();
    if(armButton){
      arm();
    }
    else if(disarmButton){
      disarm(); 
    }
    else{
      // t r p y
      dispatch(throttleControl, rollControl, pitchControl, yawControl);
  
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



