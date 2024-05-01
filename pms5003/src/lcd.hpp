#include <Wire.h>
#include <LiquidCrystal_PCF8574.h>
#include <map>

String EMPTY = "                ";

void printHeader(LiquidCrystal_PCF8574 lcd, String val)
{
    lcd.setCursor(0, 0);
    lcd.print(EMPTY);
    int l = val.length();
    int pos = l == 16 ? 0 : (16 - l) / 2;
    lcd.setCursor(pos, 0);
    lcd.print(val);
}
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

        printHeader(lcd, head);

        lcd.setCursor(0, 1);
        lcd.print(EMPTY);

        if (val.length() > 16)
        {
            lcd.setCursor(0, 1);
            String tmp = val;
            lcd.print(tmp);
            delay(1000);
            for (int i = 0; i < (val.length() - 16); i++)
            {
                tmp = tmp.substring(1);
                lcd.setCursor(0, 1);
                // lcd.print(EMPTY);
                lcd.setCursor(0, 1);
                lcd.print(tmp);
                delay(scrollSpeed);
            }
        }
        else
        {
            int l = val.length();
            int pos = l == 16 ? 0 : (16 - l) / 2;
            lcd.setCursor(pos, 1);
            lcd.print(val);
            delay(1000);
        }
        delay(1000);
    }
}
