#include <LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
const int LDR = A0;
int input_val = 0;

void setup()
{
  lcd.begin(16, 2);
  Serial.begin(9600);
  lcd.print("LDR Value is:");

}

void loop()
{
  input_val = analogRead(LDR);
  Serial.print("LDR Value is: ");
  Serial.println(input_val);
  delay(1000);
  lcd.setCursor(0, 1);
  lcd.print(input_val);

}
