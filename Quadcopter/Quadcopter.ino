// Arduino Wire library is required if I2Cdev I2CDEV_ARDUINO_WIRE implementation
// is used in I2Cdev.h
#include "Wire.h"


// I2Cdev and MPU6050 must be installed as libraries, or else the .cpp/.h files
// for both classes must be in the include path of your project
/* For the UNO:
MPU6050 - ARDUINO
GND - GND
VCC - 3.3V
SDA - A4
SCL - A5
INT - D2
THAT'S IT */
#include "I2Cdev.h"
#include "MPU6050.h"

// GYRO & ACCEL
MPU6050 accelgyro;
int16_t ax, ay, az;
int16_t gx, gy, gz;

// LCD
#include <LiquidCrystal.h>
const int numRows = 2;
const int numCols = 16;
LiquidCrystal lcd(12,11,5,4,3,2);

// WII MOTE
int nunchuckData[5];

void setup()
{
  Wire.begin();
  //lcd.begin(numCols, numRows);
  Serial.begin(9600);     // 9600 for xBee
  
  accelgyro.initialize(); // Initialize gyro/accel
  
  Serial.println("Testing device connections...");
  Serial.println(accelgyro.testConnection() ? "MPU6050 connection successful" : "MPU6050 connection failed");
  
  
}

void loop()
{ 
  
    //parseXbeeData();   // Get data from Wiimote

  /* Get data from accelerometer and gyro https://github.com/jrowberg/i2cdevlib
    https://www.sparkfun.com/products/11028 */
    
    getMotion();
    printMotion();
  
  
  
  // Adjust motor speeds 

  
}
void printMotion(){
    Serial.print("AX "); Serial.print(ax); Serial.print(" ");
    Serial.print("AY ");Serial.print(ay); Serial.print(" ");
    Serial.print("AZ ");Serial.print(az); Serial.print(" ");
    Serial.print("GX ");Serial.print(gx); Serial.print(" ");
    Serial.print("GY ");Serial.print(gy); Serial.print(" ");
    Serial.print("GZ ");Serial.println(gz); Serial.print("\n");
}
