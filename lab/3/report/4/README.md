how it works : 

We have ESP32 in Master mode and Arduino in Slave mode address 12
We created an I2C connection with all devices  ESP32, Arduino, MPU6050 and BME280

Arduino program should read input analog from A0 which is connected to a variable resistor and send it to ESP32
Here we have found some problems coding this part because I2C send only one byte so we created a buffer to send the int value (2 bytes)

and finaly we have (using the previous exemples to ) to show all this data in console

