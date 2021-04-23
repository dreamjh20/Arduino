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
}
 
void loop() {
  // Wait a few seconds between measurements.
  float dis;
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  char state = 'A';
  
  dis = 1.8*t-0.55*(1-h/100)*(1.8*t-26)+32;

  if (isnan(h) || isnan(t)) {
    Serial.println("SENSOR ERROR");
    lcd.setCursor(0, 0);
    lcd.print("     SENSOR     ");
    lcd.setCursor(0, 1);
    lcd.print("     ERROR!     ");
    return;
  }
  if(dis >= 80){
    state = 'F';
  }
  else if(dis >= 75){
    state = 'C';
  }
  else if(dis >= 68){
    state = 'B';
  }
  else{
    state = 'A';
  }
//  state = 'F';
  Serial.print("Discomfort: ");
  Serial.print(dis);
  Serial.print(" (");
  Serial.print(state);
  Serial.print(")\t");
  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.print(" *C ");
  Serial.print("\n");
  
  lcd.setCursor(1,0);
  lcd.print("Temp: ");
  lcd.print(t, 1);
  lcd.print("C");

  lcd.setCursor(14,0);
  lcd.print(dis);

  lcd.setCursor(15,1);
  lcd.print(state);
  
  lcd.setCursor(2,1);
  lcd.print("Hum: ");
  lcd.print(h, 1);
  lcd.print("%");

  if(state == 'F'){
    for(int i = 0; i < 3; i++){
      lcd.noBacklight();
      delay(100);
      lcd.backlight();
      delay(100);
    }
  }
}
