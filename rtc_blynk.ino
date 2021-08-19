#define BLYNK_PRINT Serial       
#include <SoftwareSerial.h>
#include <BlynkSimpleSerialBLE.h>
#include <TimeLib.h>
#include <WidgetRTC.h>
char auth[] = "a3rIZYquLiDBzOaKxJsxRejSDQKPuZO7";
SoftwareSerial SwSerial(2, 3); // RX, TX

WidgetLED led1(V1);       
WidgetLED led2(V2);   
WidgetRTC rtc; 
int shour = 0;
int smin = 0;  
int pin = 0;

BLYNK_WRITE (V0){ 
  TimeInputParam t(param);
  shour = t.getStartHour();
  smin = t.getStartMinute();
}

void rtcw(){
   if (shour == hour() && smin == minute()){
    led1.on();
    led2.off();
   }
   else{
    led1.off();
    led2.on();
   }
}

void setup() {
  Serial.begin(9600);
  SwSerial.begin(9600);
  Blynk.begin(SwSerial, auth);
  rtc.begin();
}
 
void loop() {
  Blynk.run(); 
  rtcw();
  
}
