  void setup() {
  pinMode(12, OUTPUT);
  Serial.begin(9600);
  digitalWrite(12, LOW);
}

void loop() {
  
  if(Serial.available())
  {
    char i = Serial.read();
    if(i == '1')
    {
      digitalWrite(12, HIGH);

      delay(120000); //2분
//      delay(1000); //1초
//      delay(60000); //1분
//      delay(300000); //5분
//      delay(600000); //10분
      
    }
  }
} 
