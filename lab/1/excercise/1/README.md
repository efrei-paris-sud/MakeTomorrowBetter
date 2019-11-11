# Exercice 1 

If we directly connect the led with potentiometer we can control brightness of led but not accurately (controlling brightness depends on the resistance of the potentiometer)

With microcontroller we can fade led with the brightness level we want.
With microcontroller their is more flexibility than the manually fading.


## code : 
```
int sensor=A0;  //Analog 0 pin named as sensor
int output=9;   //Pin-9 is declared as output

void setup()                                                          
{
pinMode(output, OUTPUT); //Pin-9 is declared as output                                                
}

void loop()
{ 
int reading=analogRead(sensor); //Reading the voltage out by potentiometer
int bright=reading/4;           //Dividing reading by 4 to bring it in range of 0 - 255                               
analogWrite(output, bright);    //Finally outputting the read value on pin-9 fading led
}  
```


I have read this article to explain difference which is very detailed :
https://www.engineersgarage.com/arduino/fading-led-with-potentiometer-using-arduino/
