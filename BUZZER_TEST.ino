#define BUZZER 11
#define VIBE A0

void setup() {
  // put your setup code here, to run once:
  pinMode(BUZZER, OUTPUT);
  pinMode(VIBE, INPUT);
  Serial.begin(9600);
}

void music(){

  for (int hz = 300; hz <= 750; hz++)
  {
    tone(BUZZER, hz);

    delay(5);
  }

  for (int hz = 750; hz >= 300; hz--)
  {
    tone(BUZZER, hz);

    delay(5);
  }
  digitalWrite(BUZZER, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  music();
  
  delay(1000);

  int val = analogRead(VIBE); 
  Serial.print("Val = "); 
  Serial.println(val);
  Serial.print("-----------\n");
  delay(1000);

}
