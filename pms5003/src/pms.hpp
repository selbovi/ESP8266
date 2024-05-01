#include <map>
#include <PMserial.h> // Arduino library for PM sensors with serial interface

String EXT1 = " [ug/m3]";

std::map<String, String> pmsAddData(SerialPM pms, std::map<String, String> data)
{
    // read the PM sensor
    pms.read();
    if (pms)
    { // successfull read
        int aqi = pms.pm25;
        if (aqi < 50) {
            data["PM 2.5"] = String(aqi) + EXT1 + " GOOD";
        } else if (aqi < 100) {
            data["PM 2.5"] = String(aqi) + EXT1 + " NORM";
        } else if (aqi < 150) {
            data["PM 2.5"] = String(aqi) + EXT1 + " BAD";
        } else {
            data["PM 2.5"] = String(aqi) + EXT1 + " CRIT";
        }


        data["PM 1.0"] = String(pms.pm01) + EXT1;
        data["PM 10"] = String(pms.pm10) + EXT1;
    }
    else
    { // something went wrong
        data["PM 1.0"] = "ERR";
        data["PM 2.5"] = "ERR";
        data["PM 10"] = "ERR";
        switch (pms.status)
        {
        case pms.OK: // should never come here
            break;   // included to compile without warnings
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

    return data;
}