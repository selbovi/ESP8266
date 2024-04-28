#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_PCF8574.h>
#include <map>

LiquidCrystal_PCF8574 lcd(0x27); // set the LCD address to 0x27 for a 16 chars and 2 line display

int show = -1;

// 2 custom characters

byte dotOff[] = {0b00000, 0b01110, 0b10001, 0b10001,
                 0b10001, 0b01110, 0b00000, 0b00000};
byte dotOn[] = {0b00000, 0b01110, 0b11111, 0b11111,
                0b11111, 0b01110, 0b00000, 0b00000};

std::vector<String> foo = {
    "short",
    "very long string bigger than 16 chars",
    "smaller string",
    "again long string bigger"};

std::map<String, String> first = {{"PMS 1.0", "v1 initialize the lcd"}, {"k2", "v2"}};

int SCROLL_SPEED = 600;
String EMPTY = "                ";

void setup()
{
  int error;

  Serial.begin(9600);
  Serial.println("LCD...");

  // wait on Serial to be available on Leonardo
  while (!Serial)
    ;

  Serial.println("Probing for PCF8574 on address 0x27...");

  // See http://playground.arduino.cc/Main/I2cScanner how to test for a I2C device.
  Wire.begin();
  Wire.beginTransmission(0x27);
  error = Wire.endTransmission();
  Serial.print("Error: ");
  Serial.print(error);

  if (error == 0)
  {
    Serial.println(": LCD found.");
    show = 0;
    lcd.begin(16, 2); // initialize the lcd

    lcd.createChar(1, dotOff);
    lcd.createChar(2, dotOn);
  }
  else
  {
    Serial.println(": LCD not found.");
  } // if

  lcd.setBacklight(255);

} // setup()

void loop()
{
  for (const auto &p : first)
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
      delay(SCROLL_SPEED);
      for (int i = 0; i < (val.length() - 17); i++)
      {
        lcd.print(EMPTY);
        tmp = tmp.substring(1);
        lcd.setCursor(0, 1);
        lcd.print(tmp);
        delay(SCROLL_SPEED);
            Serial.println(tmp);
      }
    }
    Serial.println(val);
    delay(1000);
  }
}

void loopVector()
{
  for (auto &element : foo)
  {
    lcd.home();
    lcd.clear();

    int l = element.length();
    String ln = "length = " + l;
    //  Serial.println(ln);
    if (l > 16)
    {
      lcd.print(element);
      delay(1000);
      for (int i = 0; i < l - 16; i++)
      {
        lcd.scrollDisplayLeft();
        delay(SCROLL_SPEED);
      }
      delay(SCROLL_SPEED);
    }
    else
    {
      int pos = l == 16 ? 0 : (16 - l) / 2;
      lcd.setCursor(pos, 0);
      Serial.println(pos);
      lcd.print(element);
      delay(1400);
    }
    lcd.clear();
    lcd.home();
  }
}

void loop2()
{
  if (show == 0)
  {
    lcd.setBacklight(255);
    lcd.home();
    lcd.clear();
    lcd.print("Hello LCD");
    delay(1000);

    lcd.setBacklight(0);
    delay(400);
    lcd.setBacklight(255);
  }
  else if (show == 1)
  {
    lcd.clear();
    lcd.print("Cursor On");
    lcd.cursor();
  }
  else if (show == 2)
  {
    lcd.clear();
    lcd.print("Cursor Blink");
    lcd.blink();
  }
  else if (show == 3)
  {
    lcd.clear();
    lcd.print("Cursor OFF");
    lcd.noBlink();
    lcd.noCursor();
  }
  else if (show == 4)
  {
    lcd.clear();
    lcd.print("Display Off");
    lcd.noDisplay();
  }
  else if (show == 5)
  {
    lcd.clear();
    lcd.print("Display On");
    lcd.display();
  }
  else if (show == 7)
  {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("*** first line.");
    lcd.setCursor(0, 1);
    lcd.print("*** second line.");
  }
  else if (show == 8)
  {
    lcd.scrollDisplayLeft();
  }
  else if (show == 9)
  {
    lcd.scrollDisplayLeft();
  }
  else if (show == 10)
  {
    lcd.scrollDisplayLeft();
  }
  else if (show == 11)
  {
    lcd.scrollDisplayRight();
  }
  else if (show == 12)
  {
    lcd.clear();
    lcd.print("write-");
  }
  else if (show == 13)
  {
    lcd.clear();
    lcd.print("custom 1:<\01>");
    lcd.setCursor(0, 1);
    lcd.print("custom 2:<\02>");
  }
  else
  {
    lcd.print(show - 13);
  } // if

  delay(1400);
  show = (show + 1) % 16;
} // loop()