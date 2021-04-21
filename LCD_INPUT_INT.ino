#include <hd44780.h>
#include <Wire.h>
#include <hd44780ioClass/hd44780_I2Cexp.h>

hd44780_I2Cexp lcd;

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
}


int cus = 0;
//lcd.setCursor (0, 0);
void loop() {
 
int a = 0;
Serial.print("NUM");
while(Serial.available() == 0) {}
a = Serial.parseInt();
if(a == -1)
  lcd.clear();
else
  lcd.print(a);

a = Serial.read();

}
