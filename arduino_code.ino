
#include <Wire.h>
#include "Adafruit_MPR121.h"
int in1 = 11; // Pin to provide input to relay for ON/OFF
int power = 6; // Relay power pin (Vcc) always high
boolean cs1Flag = true;
// You can have up to 4 on one i2c bus but one is enough for testing!
Adafruit_MPR121 cap = Adafruit_MPR121();




void setup()
{
   pinMode(in1, OUTPUT);
   digitalWrite(in1, HIGH);
   digitalWrite(power , HIGH);
   Serial.begin(9600);
   while (!Serial)
       { // needed to keep arduino from starting too fast!
        delay(10);
       }
  
       Serial.println("Adafruit MPR121 Capacitive Touch sensor test"); 
  
        // Default I2C address for MPR121 is 0x5A
    if (!cap.begin(0x5A)) 
    {
    Serial.println("MPR121 not found, check wiring?");
    while (1);
    }
     Serial.println("MPR121 found!");
}

void loop() 
{
  digitalWrite(in1, HIGH);// Power On the Relay


   while (cs1Flag)
   {
       Serial.println("loop 1:"); // To test if it has entered inside loop
       Serial.println(cap.touched(), HEX);  
       Serial.print("Filt: ");
       Serial.print(cap.filteredData(3)); // Filtered Data values
       Serial.println();
       Serial.print("Base: ");
       Serial.print(cap.baselineData(3)); // Baseline Data Values
       Serial.println();
       delay(100);
  

     if (cap.touched() & (1 << 3))  // Copper strips connected to 3rd channel
     {
     
         Serial.println("loop 2:");// To make sure the finger is touched and program is inside loop
         Serial.println(cap.touched(), HEX);  
         Serial.print("Filt: ");
         Serial.print(cap.filteredData(3)); 
         Serial.println();
         Serial.print("Base: ");
         Serial.print(cap.baselineData(3));
         Serial.println();
         cs1Flag = false; // To take it out of while loop
         delay(2000);  
      }
    }
 
    while(cap.touched() & (1 << 3))
    
    {
    //to keep in the loop for the whole time finger is sensed 
    digitalWrite(in1, LOW); // To power the relay  OFF
    delay(2000);
    }
    
  
     cs1Flag = true;
     Serial.print("outide loops");
     Serial.println(cap.touched(), HEX);  
     Serial.print("Filt: ");
     Serial.print(cap.filteredData(3)); 
     Serial.println();
     Serial.print("Base: ");
     Serial.print(cap.baselineData(3));
     Serial.println();
}
