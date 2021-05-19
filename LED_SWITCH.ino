#define inp 8
#define led 7
#include <Wire.h>

void setup() {
  // put your setup code here, to run once:
  pinMode(inp, INPUT);
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}
int tf = 0;
void loop() {
  // put your main code here, to run repeatedly:
  
  int State = digitalRead(inp);
  Serial.println(State);

  if(State == 1){
    Serial.print("--------II---------");
    tf = 1 - tf;
    Serial.print(tf);
    delay(400);
    //delay(5000);
  }
  if(tf == 1){
    digitalWrite(led, HIGH);
  }
  else{
    digitalWrite(led, LOW);
  }
}
