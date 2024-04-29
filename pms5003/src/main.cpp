#include <SoftwareSerial.h>
#include <MHZ19.h>
#include <mhz.hpp>
#include <LiquidCrystal_PCF8574.h>
#include <lcd.hpp>

LiquidCrystal_PCF8574 lcd(0x27); // set the LCD address to 0x27 for a 16 chars and 2 line display

int SCROLL_SPEED = 600;
std::map<String, String> data;

SoftwareSerial ss(12, 14);
MHZ19 mhz(&ss);

void setup()
{
  Serial.begin(9600);
  Serial.println(F("Starting..."));

  ss.begin(9600);
  mhz.setAutoCalibration(false);
  mhz.setRange(MHZ19_RANGE_5000);

  lcd.begin(16, 2); // initialize the lcd
  lcd.setBacklight(255);
}

void loop()
{
  Serial.println("in loop");
  data = mhzAddData(mhz, data);

  printAll(lcd, data, SCROLL_SPEED);
}