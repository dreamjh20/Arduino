#define GAS 0
#define LED 8
void setup() {
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  pinMode(GAS, INPUT);
}

void loop() {
  int val = analogRead(gas);
  if(val >= 520){
    
    digitalWrite(LED, HIGH);
  }

  if(val < 520) {
    digitalWrite(LED, LOW);
  }

  Serial.println(val);
  delay(1000);
}
