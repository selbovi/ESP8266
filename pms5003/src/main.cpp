#include <SoftwareSerial.h>
#include <MHZ19.h>

SoftwareSerial ss(12,14);
MHZ19 mhz(&ss);

void setup()
{
  Serial.begin(9600);
  Serial.println(F("Starting..."));

  ss.begin(9600);
  mhz.setAutoCalibration(false);
  mhz.setRange(MHZ19_RANGE_5000);
}

void loop()
{
  MHZ19_RESULT response = mhz.retrieveData();
  if (response == MHZ19_RESULT_OK)
  {
    Serial.print(F("CO2: "));
    Serial.println(mhz.getCO2());
    Serial.print(F("Min CO2: "));
    Serial.println(mhz.getMinCO2());
    Serial.print(F("Temperature: "));
    Serial.println(mhz.getTemperature());
    Serial.print(F("Accuracy: "));
    Serial.println(mhz.getAccuracy());
  }
  else
  {
    Serial.print(F("Error, code: "));
    Serial.println(response);
  }
  
  delay(15000);
}