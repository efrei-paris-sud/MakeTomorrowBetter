/*
 * Author: Elecrow Engle
 * Date:7/12/2017
 * IDE V1.8.2 
 * Email:engle@elecrow.com
 * Function:
 */
const int redPin = 11;
const int greenPin = 10;
const int bluePin = 9;
 
//uncomment this line if using a Common Anode LED
//#define COMMON_ANODE
 
void setup(){
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);  
}
 
void setColor(int red, int green, int blue){
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);  
}
 
void loop(){
  setColor(255, 0, 0);  // red
  delay(1000);
  setColor(0, 255, 0);  // green
  delay(1000);
  setColor(0, 0, 255);  // blue
  delay(1000);
  setColor(255, 255, 0);  // yellow
  delay(1000);  
  setColor(80, 0, 80);  // purple
  delay(1000);
  setColor(0, 255, 255);  // aqua
  delay(1000);
}


