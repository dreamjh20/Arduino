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
      delay(10000);
    }
    else digitalWrite(LED, HIGH);
  }
  
  else{
    digitalWrite(LED, LOW);
    
  }
  
  Serial.println(val);
}
