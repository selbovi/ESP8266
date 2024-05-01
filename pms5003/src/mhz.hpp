#include <MHZ19.h>
#include <map>

String EXT = " ppm ";

std::map<String, String> mhzAddData(MHZ19 mhz, std::map<String, String> data)
{
    MHZ19_RESULT response = mhz.retrieveData();
    String co2;
    String temp;
    if (response == MHZ19_RESULT_OK)
    {
        int val = mhz.getCO2();
        if (val <= 800) {
            co2 = String(val) + EXT + "GOOD";
        } else if (val <= 1000) {
            co2 = String(val) + EXT + "NORM";
        } else if (val <= 1300) {
            co2 = String(val) + EXT + "BAD";
        } else {
            co2 = String(val) + EXT + "CRIT";
        } 

        temp = String(mhz.getTemperature()) + " C";
    }
    else
    {
        co2 = temp = "ERR";
    }

    data["CO2"] = co2;
    data["TEMPERATURE"] = temp;
    return data;
}