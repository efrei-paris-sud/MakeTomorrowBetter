#define buzzer 5
void setup() {
  // initialize serial:
  Serial.begin(9600); 

}

void loop() {
  // if there's any serial available, read it:
  while (Serial.available() > 0) {
    // look for the next valid integer in the incoming serial stream:
    int i  = Serial.parseInt();
    
    // look for the newline. That's the end of your sentence:
    //if (Serial.read() == '\n') 
    //{      
    tone(buzzer,i*100, 2000);
    //}
   
  

      
    // print the three numbers in one string as hexadecimal:
    Serial.print(i, HEX);//print 
    Serial.print(i, DEC);//Print 
    Serial.println("\n"); //Print \n
    
  }