#include "DHT.h"
#include <hd44780.h>
#include <Wire.h>
#include <hd44780ioClass/hd44780_I2Cexp.h>
#define DHTPIN 2
#define DHTTYPE DHT11

hd44780_I2Cexp lcd;
DHT dht(DHTPIN, DHTTYPE);
 
void setup() {
  Serial.begin(9600);
  Serial.println("Check it out!");
  dht.begin();
  lcd.begin(16, 2);
  /*lcd.print("TEMPERATURE");
  lcd.print("Humidity");*/
}
 
void loop() {
  // Wait a few seconds between measurements.

  float h = dht.readHumidity();
  float t = dht.readTemperature();
 
  if (isnan(h) || isnan(t)) {
    Serial.println("SENSOR ERROR");
    lcd.setCursor(0, 0);
    lcd.print("     SENSOR     ");
    lcd.setCursor(0, 1);
    lcd.print("     ERROR!     ");
    return;
  }

  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.print(" *C ");
  Serial.print("\n");
  
  lcd.setCursor(1,0);
  lcd.print("Temp: ");
  lcd.print(t);
  lcd.print(" *C");
  lcd.setCursor(2,1);
  lcd.print("Hum: ");
  lcd.print(h);
  lcd.print(" %");
}
