#define inp 8
#define led 7
#define touch 9
#include <Wire.h>

void setup() {
  // put your setup code here, to run once:
  pinMode(inp, INPUT);
  pinMode(led, OUTPUT);
  pinMode(touch, INPUT);
  Serial.begin(9600);
}
int tf = 0;
void loop() {
  // put your main code here, to run repeatedly:
  
  int State = digitalRead(inp);
  int touched = digitalRead(touch);
  //Serial.println(State);

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

  
}
