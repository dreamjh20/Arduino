#include "DHT.h"
#include <hd44780.h>
#include <Wire.h>
#include <hd44780ioClass/hd44780_I2Cexp.h>
#define DHTPIN 3
#define DHTTYPE DHT11
#define RED_LED 7
#define GREEN_LED 8
#define BLUE_LED 9
#define VIBE A0
#define BUZZER 11
#define inp 6
#define led 5
#define touch 2

hd44780_I2Cexp lcd;
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  Serial.println("Check it out!");
  dht.begin();
  lcd.begin(16, 2);
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);
  pinMode(VIBE, INPUT);
  pinMode(BUZZER, OUTPUT);
  pinMode(inp, INPUT);
  pinMode(led, OUTPUT);
  pinMode(touch, INPUT);
}

int tf = 0;

void loop() {
  // Wait a few seconds between measurements.
  float dis;
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  char state = 'M';
  int vibe = analogRead(VIBE);
  int State = digitalRead(inp);
  int touched = digitalRead(touch);
  
  digitalWrite(RED_LED, LOW);
  digitalWrite(GREEN_LED, LOW);
  digitalWrite(BLUE_LED, LOW);
  
  dis = 1.8*t-0.55*(1-h/100)*(1.8*t-26)+32;
//  dis = 90;
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
    digitalWrite(RED_LED, HIGH);
  }
  else if(dis >= 75){
    state = 'C';
    digitalWrite(BLUE_LED, HIGH);
  }
  else if(dis >= 68){
    state = 'B';
    digitalWrite(BLUE_LED, HIGH);
  }
  else{
    state = 'A';
    digitalWrite(GREEN_LED, HIGH);
  }
  
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
      digitalWrite(RED_LED, LOW);
      delay(100);
      lcd.backlight();
      digitalWrite(RED_LED, HIGH);
      delay(100);
    }
  }

  Serial.println(touched);
  
  if(State == 1){
    Serial.print("--------II---------");
    tf = 1 - tf;
    Serial.print(tf);
    delay(400);
    //delay(5000);
  }
  if(tf == 1){
    if(touched == 1){
      tf = 1 - tf;
    }
    else{
      digitalWrite(led, HIGH);
    }
  }
  else{
    digitalWrite(led, LOW);
  }
  
  Serial.println(vibe);
  if(vibe > 900){
    lcd.clear();
    lcd.setCursor(3, 0);
    lcd.print("EARTHQUAKE");
    for(int m = 0; m < 5; m++){
      for (int hz = 300; hz <= 1000; hz++){
        tone(BUZZER, hz);
        delay(2);
      }
  
      for (int hz = 1000; hz >= 300; hz--){
        tone(BUZZER, hz);
        delay(2);
      }
      noTone(BUZZER);
    }
  }
}
