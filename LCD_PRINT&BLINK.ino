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
  lcd.setCursor (3,0);
  lcd.print("Hi");
  while(1){
    lcd.display();
    delay(1000);  
    lcd.noDisplay();
    delay(1000);  
  }
}
