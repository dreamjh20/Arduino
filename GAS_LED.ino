#define GAS 0
#define LED 8
#define BTN 7
#define BUZZER 11

void setup() {
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  pinMode(GAS, INPUT);
  pinMode(BTN, INPUT);
  pinMode(BUZZER, OUTPUT);  
}
int OnOff = 0;
void loop() {
  int readV = digitalRead(BTN);
  int val = analogRead(GAS);
  
  if(readV == HIGH){
    OnOff = 1 - OnOff;
    Serial.print(OnOff);
    Serial.print(" ");
    delay(400);
  }
  
  if(OnOff == 1){
    if(val >= 150){
      digitalWrite(LED, LOW);
      OnOff = 0;
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
    else digitalWrite(LED, HIGH);
  }
  
  else{
    digitalWrite(LED, LOW);
    
  }

  
  Serial.println(val);
}
