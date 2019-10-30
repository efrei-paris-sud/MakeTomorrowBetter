# Introduction

We didn't really face a challenging problems in this first lab as we did have a perfectly documented step by step tutorials with the demo codes, Otherwise, we did understand many new things about arduino and we learned how to program some small project 

## Analog input diagram

![](https://lh3.googleusercontent.com/ESRgQxQhq_0t2QsGiVdSGTpDUPBjTY-nobYc67rJRjffbJkxk4quKJtCZDcrwgZpS-f3CkqpKYhy "Analog i nput")

## Analog input code : 

int sensorPin = A0;    // select the input pin for the potentiometer
int ledPin = 13;      // select the pin for the LED
int sensorValue = 0;  // variable to store the value coming from the sensor

void setup() {
  // declare the ledPin as an OUTPUT:
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // read the value from the sensor:
  sensorValue = analogRead(sensorPin);
  // turn the ledPin on
  digitalWrite(ledPin, HIGH);
  // stop the program for <sensorValue> milliseconds:
  delay(sensorValue);
  // turn the ledPin off:
  digitalWrite(ledPin, LOW);
  // stop the program for for <sensorValue> milliseconds:
  delay(sensorValue);
}

As It's explained, We take a value from the potentiometer with the function analogRead and put it in ledPin with digitalWrite



## Fading exemple Diagram
![](https://lh3.googleusercontent.com/0YqCg2TJ3RrUQyhvZ_-3W7RBwCjg8k52_Q_RfDWR0URBWivu436VGTkpvLoUo9V3dixcJyYOtW5l)
## Fading exemple Code
We have used the analogWrite() function in
 this exemple

int ledPin = 9;    // LED connected to digital pin 9

void setup() {
  // nothing happens in setup
}

void loop() {
  // fade in from min to max in increments of 5 points:
  for (int fadeValue = 0 ; fadeValue <= 255; fadeValue += 5) {
    // sets the value (range from 0 to 255):
    analogWrite(ledPin, fadeValue);
    // wait for 30 milliseconds to see the dimming effect
    delay(30);
  }

  // fade out from max to min in increments of 5 points:
  for (int fadeValue = 255 ; fadeValue >= 0; fadeValue -= 5) {
    // sets the value (range from 0 to 255):
    analogWrite(ledPin, fadeValue);
    // wait for 30 milliseconds to see the dimming effect
    delay(30);
  }
}
Here is to set a for loop changing from 0 to 255 and put value in ledPin every time with analogWrite function
