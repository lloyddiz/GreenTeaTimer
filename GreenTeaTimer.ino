/*
Sun Dec 22 19:41:11 CET 2013, LDIZON
Green tea timer, arduino code
*/


#include <Wire.h> // Enable this line if using Arduino Uno, Mega, etc.
//#include <TinyWireM.h> // Enable this line if using Adafruit Trinket, Gemma, etc.

#include "Adafruit_LEDBackpack.h"
#include "Adafruit_GFX.h"

Adafruit_7segment matrix = Adafruit_7segment();
const int buttonpin_50 = 2;     // the number of the pushbutton pin
const int buttonpin_20 = 9;     // the number of the pushbutton pin
const int ledPin =  13;         // the number of the LED pin
int button_state_50 = 0;         // variable for reading the pushbutton status
int button_state_20 = 0;         // variable for reading the pushbutton status

void setup() {
#ifndef __AVR_ATtiny85__
  Serial.begin(9600);
  Serial.println("Running green tea timer");
#endif
   matrix.begin(0x70);
   // initialize the LED pin as an output:
   pinMode(ledPin, OUTPUT);      
   // initialize the pushbutton pin as an input:
   pinMode(buttonpin_50, INPUT); 
   pinMode(buttonpin_20, INPUT);    
   matrix.clear();
   matrix.writeDisplay();
}


void loop() {

   button_state_50 = digitalRead(buttonpin_50);
   button_state_20 = digitalRead(buttonpin_20);

   if (button_state_50 == HIGH) {
      digitalWrite(ledPin, HIGH);  
      countdown(50, matrix);
   } 
   else if (button_state_20 == HIGH) {
      digitalWrite(ledPin, HIGH);  
      countdown(20, matrix);
   } 
   else {
      digitalWrite(ledPin, LOW); 
   }


}


void countdown(int secs, Adafruit_7segment matrix) {
      for (int counter = secs; counter > -1; counter-- ) {
         matrix.writeDigitNum(3, counter / 10);
         matrix.writeDigitNum(4, counter % 10);
         matrix.writeDisplay();
         delay(1000);
      }
      delay(3000);
      matrix.clear();
      matrix.writeDisplay();
}
