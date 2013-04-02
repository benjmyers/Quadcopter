/*
  XBeeMessage
 Send a message to an XBee using its address
 This is from the Arduino Cookbook, V2, Margolis
 */

void sendData(){
  if (radioConfigured) {
    Serial.print("Hello!");      // WRITE DATA HERE. This will be where we write the nunchuck values.
    delay(3000);
  }
  else {
    delay(30000);     // Wait 30 seconds
    radioConfigured = configureRadio(); // try again
  } 
}

boolean configureRadio() {
  // put the radio in command mode:
  Serial.print("+++");
  String ok_response = "OK\r"; // the response we expect.
  // Read the text of the response into the response variable
  String response = String("");
  while (response.length() < ok_response.length()) {
    if (Serial.available() > 0) {
      response += (char) Serial.read();
    }
  }
  // If we got the right response, configure the radio and return true.
  if (response.equals(ok_response)) {
    Serial.print("ATDH0013A200\r"); // destination high-REPLACE THIS
    Serial.print("ATDL403B9E1E\r"); // destination low-REPLACE THIS
    Serial.print("ATCN\r");     // back to data mode
    return true;
  } 
  else {
    return false; // This indicates the response was incorrect.
  }
}


