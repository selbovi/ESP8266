#ifndef ESP32
#include <SoftwareSerial.h>
#endif
#include <PMserial.h> // Arduino library for PM sensors with serial interface
#include <Stream.h>
#include <string>
#include <vector>
#include <local.hpp>
/**
 * Инфо о частицах, мониторинг + концентрация
 * https://aqicn.org/city/moscow
 * 
PM2.5
0 - 50 	Good 	Air quality is considered satisfactory, and air pollution poses little or no risk 	None
51 -100 	Moderate 	Air quality is acceptable; however, for some pollutants there may be a moderate health concern for a very small number of people who are unusually sensitive to air pollution. 	Active children and adults, and people with respiratory disease, such as asthma, should limit prolonged outdoor exertion.
101-150 	Unhealthy for Sensitive Groups 	Members of sensitive groups may experience health effects. The general public is not likely to be affected. 	Active children and adults, and people with respiratory disease, such as asthma, should limit prolonged outdoor exertion.
151-200 	Unhealthy 	Everyone may begin to experience health effects; members of sensitive groups may experience more serious health effects 	Active children and adults, and people with respiratory disease, such as asthma, should avoid prolonged outdoor exertion; everyone else, especially children, should limit prolonged outdoor exertion
201-300 	Very Unhealthy 	Health warnings of emergency conditions. The entire population is more likely to be affected. 	Active children and adults, and people with respiratory disease, such as asthma, should avoid all outdoor exertion; everyone else, especially children, should limit outdoor exertion.
300+ 	Hazardous 	Health alert: everyone may experience more serious health effects 	Everyone should avoid all outdoor exertion

*/

void setup()
{
	Serial.begin(9600);
}

void loop()
{

	//прочитать значения датчика

	//заполнить массив строк с результатами для вывода
	std::vector<std::string> info = getInfo(0, 40, 50); //fixme
	//зажечь светодиод по необходимости

	//отобразить значения на экране
}