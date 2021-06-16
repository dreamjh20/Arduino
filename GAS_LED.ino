#define GAS 0
#define LED 8
#define BTN 7
void setup() {
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  pinMode(GAS, INPUT);
  pinMode(BTN, INPUT);
  
}
int OnOff = 0;
void loop() {
  int val = analogRead(GAS);
  
  if(BTN == HIGH){
    OnOff = 1 - OnOff;
    Serial.print(OnOff);
    delay(400);
  }
  
  if(OnOff == 1){
    digitalWrite(LED, HIGH);
  }
  
  else{
    digitalWrite(LED, LOW);
    if(val >= 160){
      digitalWrite(LED, HIGH);
    }
  }


  if(OnOff == 1){
    if(BTN == HIGH){
      OnOff = 1 - OnOff;
    }
    else{
      digitalWrite(LED, HIGH);
    }
  }
  else{
    digitalWrite(LED, LOW);
  }

  
  Serial.println(val);
  delay(1000);
}
