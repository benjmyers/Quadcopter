// Arduino Wire library is required if I2Cdev I2CDEV_ARDUINO_WIRE implementation
// is used in I2Cdev.h
#include "Wire.h"


// I2Cdev and MPU6050 must be installed as libraries, or else the .cpp/.h files
// for both classes must be in the include path of your project
//#include "I2Cdev.h"
//#include "MPU6050.h"

// class default I2C address is 0x68
// specific I2C addresses may be passed as a parameter here
// AD0 low = 0x68 (default for InvenSense evaluation board)
// AD0 high = 0x69
//MPU6050 accelgyro;

int16_t ax, ay, az;
int16_t gx, gy, gz;


#include <LiquidCrystal.h>
const int numRows = 2;
const int numCols = 16;
LiquidCrystal lcd(12,11,5,4,3,2);

int nunchuckData[5];

void setup()
{
  lcd.begin(numCols, numRows);
  //lcd.scrollDisplayLeft();
  Serial.begin(9600);     // 9600 for xBee
  
 // accelgyro.initialize(); // Initialize gyro/accel
  
  /*Serial.println("Testing device connections...");
  Serial.println(accelgyro.testConnection() ? "MPU6050 connection successful" : "MPU6050 connection failed");
  */
  
}

void loop()
{ 
  
    parseXbeeData();   // Get data from Wiimote

  /* Get data from accelerometer and gyro https://github.com/jrowberg/i2cdevlib
    https://www.sparkfun.com/products/11028 */
    
 // getMotion();
  
  
  
  // Adjust motor speeds 

  
}
