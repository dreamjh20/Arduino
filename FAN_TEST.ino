#include <Wire.h> 

#define fan 3
void setup() {
  // put your setup code here, to run once:
  pinMode(fan, OUTPUT);
  digitalWrite(fan, HIGH);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(fan, HIGH);
  delay(200);
  digitalWrite(fan, LOW);
  delay(10);
  Serial.print("-\n");
}
