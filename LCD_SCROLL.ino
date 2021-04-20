#include <hd44780.h>
#include <Wire.h>
#include <hd44780ioClass/hd44780_I2Cexp.h>

hd44780_I2Cexp lcd;
void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2);
}
void loop() {
  // put your main code here, to run repeatedly:
  lcd.setCursor (19,1);
  lcd.print("SilverBeen");

  lcd.setCursor (16,0);
  lcd.print("I love");
 
  lcd.scrollDisplayLeft();
  delay(1000); 

  
}
