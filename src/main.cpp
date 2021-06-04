#include <Arduino.h>
#include "LiquidCrystal_I2C.h"

LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 16, 2); // Change to (0x27,20,4) for 20x4 LCD.

void setup()
{
  Serial.begin(9600);

  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
}

void loop()
{
  if (Serial.available() > 0)
  {
    // read the incoming byte:
    char ch = (char)Serial.read();
    auto str = String(ch);
    Serial.print(ch);

    if (ch == '[')
    {
      lcd.setCursor(0, 0);
      lcd.print("                ");
      lcd.setCursor(0, 0);
    }
    else if (ch == ']')
    {
      lcd.setCursor(0, 1);
      lcd.print("                ");
      lcd.setCursor(0, 1);
    }
    else if (ch > 31)
    {
      lcd.print(ch);
    }
  }
}