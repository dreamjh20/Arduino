#include <Servo.h>
#define CDS A0

Servo sv;

void setup() 
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(CDS,INPUT);
  sv.attach(9);
}

void loop() 
{
  // put your main code here, to run repeatedly:
  int cds;
  cds = analogRead(CDS);
  Serial.println(cds);
  if(cds < 25)
  {
      delay(100);
      sv.write(7);
      delay(400);                             
      sv.write(15);
  }
}
