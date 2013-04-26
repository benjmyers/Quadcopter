

// -------------------------------------
// ---- LCD Display --------------------
// -------------------------------------
/*#include <LiquidCrystal.h>
 const int numRows = 2;
 const int numCols = 16;
 LiquidCrystal lcd(12,11,5,4,3,2);*/

// -------------------------------------
// ---- Motors -------------------------
// -------------------------------------
Servo motor_1, motor_2;
int speed_1, speed_2;
const int switch_1 = 6;
const int switch_2 = 5;
const int motor_1_pin = 9;
const int motor_2_pin = 10;
boolean calibrated = false;


int nunchuckData[5];

void setup()
{
  Serial.begin(9600);     // 9600 for xBee
  // Initialize Gyro and Accel
  Wire.begin();
  Serial.println("Initialize Gyro");
  accelgyro.initialize(); // Initialize gyro/accel
  Serial.println("Testing device connections...");
  Serial.println(accelgyro.testConnection() ? "MPU6050 connection successful" : "MPU6050 connection failed");

  // Set up the motors
  pinMode(switch_1, INPUT);
  pinMode(switch_2, INPUT);
  motor_1.attach(motor_1_pin);  // attaches the servo on pin 9 to the servo object 
  motor_2.attach(motor_2_pin);
  speed_1 = 120;
  speed_2 = 120;
  
}

void loop()
{ 

  // ------ Calibrate Motors ------
  if(!calibrated){
    calibrate();
  }
  // ----- Control Flight ----
  else{
    // Get data from Wiimote
    parseXbeeData();   
    printInput();
    
    // Get motion from Accel and Gyro
    getMotion();
    printMotion();
  
    // Analyse Data
    assess();
    Serial.print("S1: ");Serial.print(speed_1);
    Serial.print(" S2: ");Serial.println(speed_2);
    
    if(digitalRead(switch_1)!=0){
      modSpeed();  
    }
  }


}
void assess(){
  // Motor One Lower
  if(ay > 1000){
    speed_1 += 5;
    speed_2 -= 5;
  }
  // Motor Two Lower
  else if (ay < -1000){
    speed_1 -= 5;
    speed_2 += 5;
  }  

}

void calibrate(){
  // THROTTLE HIGH
  if(digitalRead(switch_1)!=0){
    servo_1.write(180);
    servo_2.write(180);
  }
  // THROTTLE LOW
  else{
    servo_1.write(90);
    servo_2.write(90);
    calibrate = true;
  }
  
  delay(15);  

}
void modSpeed(){

  for(int i=0; i < 5; i++)  // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    servo_1.write(speed_1+i);              // tell servo to go to position in variable 'pos' 
    servo_2.write(speed_2+i); 
    delay(15);                       // waits 15ms for the servo to reach the position 
  } 
  for(int i=5; i >= 0; i--)     // goes from 180 degrees to 0 degrees 
  {                                
    servo_1.write(speed_1-i);              // tell servo to go to position in variable 'pos' 
    servo_2.write(speed_2-i); 
    delay(15);                       // waits 15ms for the servo to reach the position 
  } 
}
