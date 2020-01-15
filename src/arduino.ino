#include <Wire.h>
#include <ArduinoJson.h>

void setup() {
  // Define the LED pin as Output
  Serial.begin(9600);
  // Start the I2C Bus as Slave on address 9
  Wire.begin(9);
  Serial.println("Ok"); 
  pinMode(11,OUTPUT);
  Wire.onReceive(receiveEvent);
  Wire.onRequest(requestEvent);

}


void requestEvent() {
   int sensorValue = analogRead(A0);

  uint8_t buffer[2];
  buffer[0] = sensorValue >> 8;
  buffer[1] = sensorValue & 0xff;
  Wire.write(buffer, 2);
  Serial.println(sensorValue);
}

// function that executes when data is received from master
void receiveEvent(int howMany) {
  String data="";
 while (0 <Wire.available()) {
    char c = Wire.read();      /* receive byte as a character */
    data += c;
    
  }
    Serial.println(data);           /* print the request data */
    processCall(data);         /* to newline */
}

void processCall(String command){

    StaticJsonDocument<200> doc;
   DeserializationError error = deserializeJson(doc, command);
    if (error) {
    Serial.print(F("deserializeJson() failed: "));
    Serial.println(error.c_str());
    return;
  }
  double gpio = doc["gpio"];
  double state = doc["state"];

  // Print values.
  Serial.println(gpio);
  Serial.println(state);
  digitalWrite(gpio, state);
}


void loop() {
 delay(100);

 
}
