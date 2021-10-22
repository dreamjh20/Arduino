#define LED 13

int input_data;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  digitalWrite(LED,LOW);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  while(Serial.available())
  {
    input_data = Serial.read();
  }

  if(input_data == '1')
  {
    digitalWrite(LED, HIGH); // led_on
  }
  else if(input_data == '0')
  {
    digitalWrite(LED, LOW); // led_off
  }
}
