#ifndef ESP32
#include <SoftwareSerial.h>
#endif
#include <PMserial.h> // Arduino library for PM sensors with serial interface
#include <Stream.h>

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
		if (Serial.find(66))
		{ // 0x42
			Serial.println("found 0x42");
			ch = Serial.read();
			Serial.println(ch);
			if (ch == 77)
			{ // 0x4d

				for (int i = 0; i < 30; i++)
				{
					ch = Serial.read();
					Serial.println(ch);
				}
			}
		}
		Serial.println(" ========================================== ");
		return;
	}
	delay(5000);
}