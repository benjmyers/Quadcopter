
  
  
  
  /* Get data from accelerometer and gyro https://github.com/jrowberg/i2cdevlib
   https://www.sparkfun.com/products/11028 */
  void getMotion(){
   // read raw accel/gyro measurements from device
   accelgyro.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
   dx = last_ax - ax;
   dy = last_ay - ay;
   last_ax = ax;
   last_ay = ay;
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
   
