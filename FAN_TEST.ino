#include <Wire.h> 

#define fan 7
void setup() {
  // put your setup code here, to run once:
  pinMode(fan, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(fan, HIGH);
  Serial.print("-\n");
}
