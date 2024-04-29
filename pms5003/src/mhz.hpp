#include <MHZ19.h>
#include <map>

std::map<String, String> mhzAddData(MHZ19 mhz, std::map<String, String> data)
{
    MHZ19_RESULT response = mhz.retrieveData();
    String co2;
    String temp;
    if (response == MHZ19_RESULT_OK)
    {
        co2 = String(mhz.getCO2()) + " ppm";
        temp = String(mhz.getTemperature()) + " c";
    }
    else
    {
        co2 = temp = "ERR";
    }

     data["CO2"] = co2;
     data["temperature"] = temp;
    // data = {{"CO2", co2}, {"temperature", temp}};
    return data;
}