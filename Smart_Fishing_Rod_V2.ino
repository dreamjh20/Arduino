#define VIBE A0
#define COUNT 5
#define LED 7
#define BUZZER 3
#define LED2 A1

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("------------SFR------------");
  pinMode(VIBE, INPUT);
  pinMode(COUNT, INPUT);
  pinMode(LED, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  digitalWrite(LED, LOW);
}

int led_2 = 1;

void loop() {
  // put your main code here, to run repeatedly:
  int up = digitalRead(COUNT);
  
  
  if(up == HIGH)
  {
    led_2 = 1 - led_2;
    
  }
  Serial.print("----");
  Serial.print(up);
  Serial.print("----");
  Serial.println(led_2);
  if(led_2 == 1)
  {
    digitalWrite(LED2, HIGH);
  }
  else
  {
    digitalWrite(LED2, LOW);
  }
  int bite = analogRead(VIBE);
  Serial.println(bite);
  if(bite > 700)
  {
    for(int i = 0; i < 50; i++)
    {
      digitalWrite(LED, HIGH);
      delay(30);
      digitalWrite(LED, LOW);
      delay(30);
    }
    digitalWrite(LED, HIGH);
    for(int i = 0; i < 40; i++)
    {
      digitalWrite(BUZZER, HIGH);
      delay(50);
      digitalWrite(BUZZER, LOW);
      delay(50);
    }
  
  }
  digitalWrite(LED, LOW);
  noTone(BUZZER);
  delay(300);
}
