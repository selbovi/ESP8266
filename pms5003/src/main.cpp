#ifndef ESP32
#include <SoftwareSerial.h>
#endif
#include <PMserial.h> // Arduino library for PM sensors with serial interface


void setup()
{
  Serial.begin(9600);

}

void loop()
{
 while (Serial.available())
 {
	int ch = Serial.read();
	Serial.println(ch, HEX);
	delay(300);
 }
 
}