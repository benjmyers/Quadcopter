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
  
  int16_t ax, ay, az;
  int16_t gx, gy, gz;
  
  
  
  /* Get data from accelerometer and gyro https://github.com/jrowberg/i2cdevlib
   https://www.sparkfun.com/products/11028 */
  void getMotion(){
   // read raw accel/gyro measurements from device
   accelgyro.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
  }
  
  void printMotion(){
       Serial.print("a/g:\t");
      Serial.print(ax); Serial.print("\t");
      Serial.print(ay); Serial.print("\t");
      Serial.print(az); Serial.print("\t");
      Serial.print(gx); Serial.print("\t");
      Serial.print(gy); Serial.print("\t");
      Serial.println(gz);
  } 
   
