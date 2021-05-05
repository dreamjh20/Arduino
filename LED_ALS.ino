#define PWM_PIN 12

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(PWM_PIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int ALS = analogRead(A0);
  Serial.println(ALS);
  analogWrite(PWM_PIN, ALS);
  
}
