
#define BLYNK_PRINT Serial

#include <Wire.h>
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
int pin = 2;
// prototypes
void gpao11on();
void gpao11off();
void myTimerEvent();

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "19IYlIIvAeFSKKRDoOC8E7s6VnbiWdRh";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Hatem";
char pass[] = "wifipass";

BlynkTimer timer;

void myTimerEvent()
{
  int available = Wire.requestFrom(9, 2);
  int b;
  if(available == 2)
  {
    int receivedValue = Wire.read() << 8 | Wire.read(); 
    Serial.print(receivedValue);
    b = receivedValue;
  }
  Blynk.virtualWrite(V5, millis() / 1000);

  Blynk.virtualWrite(V7, b);

}

BLYNK_WRITE(V1)
{
  int pinValue = param.asInt(); // assigning incoming value from pin V1 to a variable
  // You can also use:
  // String i = param.asStr();
  // double d = param.asDouble();
  Serial.print("V1 Slider value is: ");
  Serial.println(pinValue);
  if (pinValue==0){
  gpao11on();
  } else { 
  gpao11off();} 
}




void setup()
{
  // Debug console
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  pinMode(pin, OUTPUT); 
  pinMode(pin, HIGH);
 
  // You can also specify server:
  //Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 80);
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8080);
  Wire.begin(); 
  timer.setInterval(1000L, myTimerEvent);

}

void loop()
{
  Blynk.run();
  timer.run(); // Initiates BlynkTimer
}


void gpao11on() {
    Serial.print("Switch 2 turn on ...");
      Wire.beginTransmission(9); 
      Wire.write("{\"gpio\":11,\"state\":1}");
      Wire.endTransmission();   
}

void gpao11off() {
    Serial.print("Switch 2 turn on ...");
      Wire.beginTransmission(9); 
      Wire.write("{\"gpio\":11,\"state\":0}");
      Wire.endTransmission(); 
}
