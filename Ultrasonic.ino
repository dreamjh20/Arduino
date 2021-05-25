#define TRIG 9
#define ECHO 8

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:


long duration, distance;
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  duration = pulseIn (ECHO, HIGH);
  distance = duration * 17 / 1000; 
  Serial.println(duration );
  Serial.print("\nDIstance : ");
  Serial.print(distance);
  Serial.println(" Cm");
  delay(1000);
}
