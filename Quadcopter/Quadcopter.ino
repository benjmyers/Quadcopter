

  // -------------------------------------
  // ---- LCD Display --------------------
  // -------------------------------------
  #include <LiquidCrystal.h>
   const int numRows = 2;
   const int numCols = 16;
   LiquidCrystal lcd(12,11,5,4,3,2);
  
  // -------------------------------------
  // ---- Motors -------------------------
  // -------------------------------------
  #include <Servo.h> 
  Servo motor_1;
  Servo motor_2;
  int speed_1, speed_2;
  const int switch_1 = 6;
  const int switch_2 = 5;
  const int motor_1_pin = 9;
  const int motor_2_pin = 10;
  boolean calibrate = false;

  // -------------------------------------
  // ---- Gyro & Accel--------------------
  // -------------------------------------
  // Arduino Wire library is required if I2Cdev I2CDEV_ARDUINO_WIRE implementation
  // is used in I2Cdev.h
  #include "Wire.h"
  
  // I2Cdev and MPU6050 must be installed as libraries, or else the .cpp/.h files
  // for both classes must be in the include path of your project
  #include "I2Cdev.h"
  #include "MPU6050.h"
  
  // class default I2C address is 0x68
  // specific I2C addresses may be passed as a parameter here
  // AD0 low = 0x68 (default for InvenSense evaluation board)
  // AD0 high = 0x69
  MPU6050 accelgyro;
  int16_t last_ax,last_ay;
  int dx = 0;
  int dy = 0;
  int16_t ax, ay, az;
  int16_t gx, gy, gz;
  
  const int y_tolerance = 5000;
  const int maxSpeed = 120;
  
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
  
  accelgyro.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
  last_ax = ax;
  last_ay = ay;
  
  //set up lcd
  lcd.begin(16,2);
  
  // Set up the motors
  pinMode(switch_1, INPUT);
  pinMode(switch_2, INPUT);
  motor_1.attach(motor_1_pin);  // attaches the servo on pin 9 to the servo object 
  motor_2.attach(motor_2_pin);
  speed_1 = 115;
  speed_2 = 115;
  
}

void loop()
{ 
  
  // ------ Calibrate Motors ------
  if(!calibrate){
    calibrateMotors();
  }
  // ----- Control Flight ----
  else{
    // Get data from Wiimote
    parseXbeeData();   
    printInput();

    // Get motion from Accel and Gyro
    getMotion();
    //printMotion();
  
    // Analyse Data
    assess();
    
     if(digitalRead(switch_1)!=0){
      modSpeed();  
    }
    else{
       motor_1.write(90);
      motor_2.write(90); 
    }
  }


}
void assess(){
  getSpeed();
  // Motor One Lower
  if(ay > y_tolerance){
    if(speed_1 < maxSpeed){
        speed_1 = getSpeed();
    }
    speed_2 = 110;
  //printSpeeds();
  }
  // Motor Two Lower
  else if (ay < -y_tolerance){
      speed_1 = 110;
      if(speed_2 < maxSpeed){
        speed_2 = getSpeed();
      }  
  //printSpeeds();
  } 
  else{
    speed_1 = maxSpeed;
    speed_2 = maxSpeed;
    //Serial.println("Level?");
  }

}
int getSpeed(){
  if(dy <= 200){
    return 110;
  }
  else if (dy > 200 && dy <= 1000){
    return 130;
  }
  else if (dy > 1000 && dy <= 10000){
    return 150;
  }
  else{
    return 170;
  }
 
}
void printSpeeds(){
    Serial.print("ay: ");Serial.print(ay);
    Serial.print(" S1: ");Serial.print(speed_1);
    Serial.print(" S2: ");Serial.println(speed_2);
}
void calibrateMotors(){
  Serial.println("Calibrating...");
  // THROTTLE HIGH
  if(digitalRead(switch_1)!=0){
    motor_1.write(180);
    motor_2.write(180);
  }
  // THROTTLE LOW
  else{
    motor_1.write(90);
    motor_2.write(90);
    calibrate = true;

    Serial.println("Calibrated");
  }
  
  delay(15);  

}
void modSpeed(){
//    Serial.print("S1: ");Serial.print(speed_1);
//    Serial.print(" S2: ");Serial.println(speed_2);
  for(int i=1; i <= 5; i++)                  // goes from 0 degrees to 180 degrees 
  {                                         // in steps of 1 degree 
    motor_1.write(speed_1+i);              // tell servo to go to position in variable 'pos' 
    motor_2.write(speed_2+i); 
    //delay(15);                           // waits 15ms for the servo to reach the position 
  } 
  for(int i=1; i <= 5; i++)             // goes from 180 degrees to 0 degrees 
  {                                
    motor_1.write(speed_1-i);              // tell servo to go to position in variable 'pos' 
    motor_2.write(speed_2-i); 
    //delay(15);                         // waits 15ms for the servo to reach the position 
  } 
}
