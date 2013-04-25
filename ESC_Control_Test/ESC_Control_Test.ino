// Sweep
// by BARRAGAN <http://barraganstudio.com> 
// This example code is in the public domain.


#include <Servo.h> 

Servo servo_1;  // create servo object to control a servo 
// a maximum of eight servo objects can be created 
Servo servo_2;

int pos = 0;    // variable to store the servo position 
const int switch_1 = 6;
const int switch_2 = 5;
boolean calibrated_1 = false;
boolean calibrated_2 = false;

void setup() 
{ 
  Serial.begin(9600);
  pinMode(switch_1, INPUT);
  pinMode(switch_2, INPUT);
  servo_1.attach(9);  // attaches the servo on pin 9 to the servo object 
  servo_2.attach(10);
} 


void loop() 
{ 

  if(!calibrated_1){
    // THROTTLE HIGH
    if(digitalRead(switch_1)!=0){
      servo_1.write(180);
      servo_2.write(180);
    }
    // THROTTLE LOW
    else{
      servo_1.write(90);
      servo_2.write(90);
      calibrated_1 = true; 
    }
  }
  else{
    if(digitalRead(switch_1)!=0)
      modSpeed(); 
   
  }
  delay(15);  
}

void calibrate(){

}
void modSpeed(){
  int posMin = 105;
  int posMax = 110;
  for(pos = posMin; pos < posMax; pos += 1)  // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    servo_1.write(pos);              // tell servo to go to position in variable 'pos' 
    servo_2.write(pos); 
    delay(15);                       // waits 15ms for the servo to reach the position 
  } 
  for(pos = posMax; pos>=posMin; pos-=1)     // goes from 180 degrees to 0 degrees 
  {                                
    servo_1.write(pos);              // tell servo to go to position in variable 'pos' 
    servo_2.write(pos); 
    delay(15);                       // waits 15ms for the servo to reach the position 
  } 
}

