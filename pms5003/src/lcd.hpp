#include <Wire.h>
#include <LiquidCrystal_PCF8574.h>
#include <map>

String EMPTY = "                ";

/**
 * #include <map>
 * std::map<String, String> first = {{"PMS 1.0", "vcc initialize the lcd"}, {"k2", "v2"}};
*/
void printAll(LiquidCrystal_PCF8574 lcd, std::map<String, String> map, int scrollSpeed)
{
    for (const auto &p : map)
    {
        String head = p.first;
        String val = p.second;
        lcd.home();
        lcd.clear();

        int l = head.length();
        int pos = l == 16 ? 0 : (16 - l) / 2;
        lcd.setCursor(pos, 0);
        lcd.print(head);
        lcd.setCursor(0, 1);
        lcd.print(val);
        delay(1000);
        if (val.length() > 16)
        {
            lcd.setCursor(0, 1);
            String tmp = val.substring(1);
            lcd.print(EMPTY);
            lcd.setCursor(0, 1);
            lcd.print(tmp);
            delay(scrollSpeed);
            for (int i = 0; i < (val.length() - 17); i++)
            {
                lcd.print(EMPTY);
                tmp = tmp.substring(1);
                lcd.setCursor(0, 1);
                lcd.print(tmp);
                delay(scrollSpeed);
            }
        }
        delay(1000);
    }
}