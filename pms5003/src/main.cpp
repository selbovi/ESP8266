#ifndef ESP32
#include <SoftwareSerial.h>
#endif
#include <PMserial.h> // Arduino library for PM sensors with serial interface
#include <Stream.h>

#define MSG "PMSx003 on HardwareSerial"

SerialPM pms(PMSx003, Serial); // PMSx003, UART

void setup()
{
	Serial.begin(9600);

	Serial.println(F(MSG));
	pms.init();
}

void loop()
{

	// read the PM sensor
	pms.read();
	if (pms)
	{ // successfull read
	  // print formatted results
		Serial.printf("PM1.0 %2d, PM2.5 %2d, PM10 %2d [ug/m3]\n",
					  pms.pm01, pms.pm25, pms.pm10);

		if (pms.has_temperature_humidity() || pms.has_formaldehyde())
			Serial.printf("%5.1f °C, %5.1f %%rh, %5.2f mg/m3 HCHO\n",
						  pms.temp, pms.rhum, pms.hcho);
	}
	else
	{ // something went wrong
		switch (pms.status)
		{
		case pms.OK: // should never come here
			break;	 // included to compile without warnings
		case pms.ERROR_TIMEOUT:
			Serial.println(F(PMS_ERROR_TIMEOUT));
			break;
		case pms.ERROR_MSG_UNKNOWN:
			Serial.println(F(PMS_ERROR_MSG_UNKNOWN));
			break;
		case pms.ERROR_MSG_HEADER:
			Serial.println(F(PMS_ERROR_MSG_HEADER));
			break;
		case pms.ERROR_MSG_BODY:
			Serial.println(F(PMS_ERROR_MSG_BODY));
			break;
		case pms.ERROR_MSG_START:
			Serial.println(F(PMS_ERROR_MSG_START));
			break;
		case pms.ERROR_MSG_LENGTH:
			Serial.println(F(PMS_ERROR_MSG_LENGTH));
			break;
		case pms.ERROR_MSG_CKSUM:
			Serial.println(F(PMS_ERROR_MSG_CKSUM));
			break;
		case pms.ERROR_PMS_TYPE:
			Serial.println(F(PMS_ERROR_PMS_TYPE));
			break;
		}
	}

	// wait for 10 seconds
	delay(10000);
}