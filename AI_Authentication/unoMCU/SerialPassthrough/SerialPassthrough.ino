/*
  SerialPassthrough sketch

  Some boards, like the Arduino 101, the MKR1000, Zero, or the Micro, have one
  hardware serial port attached to Digital pins 0-1, and a separate USB serial
  port attached to the IDE Serial Monitor. This means that the "serial
  passthrough" which is possible with the Arduino UNO (commonly used to interact
  with devices/shields that require configuration via serial AT commands) will
  not work by default.

  This sketch allows you to emulate the serial passthrough behaviour. Any text
  you type in the IDE Serial monitor will be written out to the serial port on
  Digital pins 0 and 1, and vice-versa.

  On the 101, MKR1000, Zero, and Micro, "Serial" refers to the USB Serial port
  attached to the Serial Monitor, and "Serial1" refers to the hardware serial
  port attached to pins 0 and 1. This sketch will emulate Serial passthrough
  using those two Serial ports on the boards mentioned above, but you can change
  these names to connect any two serial ports on a board that has multiple ports.

  created 23 May 2016
  by Erik Nyquist
*/
#include <Servo.h>
 
int servoPin = 9;
 
Servo servo;  
 
int servoAngle = 0;   // servo position in degrees
 

void setup() {
  Serial.begin(9600);
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  servo.attach(servoPin);
}

void loop() {
  
  int terminal = 55;
  
  //if (Serial.available()) {      // If anything comes in Serial (USB),
    //Serial.write(Serial.read());   // read it and send it out Serial1 (pins 0 & 1)
    terminal = Serial.read();
    if( '1' == terminal)
    {
       digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level) 
       servo.write(135);      // Turn SG90 servo Left to 45 degrees
    }
    if( '2' == terminal )
    {
       digitalWrite(LED_BUILTIN, LOW);   // turn the LED on (HIGH is the voltage level) 
       servo.write(45);      // Turn SG90 servo Left to 45 degrees
    }
    
    
  //}
  
}
