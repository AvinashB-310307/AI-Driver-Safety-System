int alcoholSensor = A0;
int eyeBlinkSensor = 2;
int buzzer = 8;
int relay = 7;

void setup() {
  pinMode(eyeBlinkSensor, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(relay, OUTPUT);

  Serial.begin(9600);
}

void loop() {

  int alcoholValue = analogRead(alcoholSensor);
  int eyeState = digitalRead(eyeBlinkSensor);

  if(alcoholValue > 400) {
    digitalWrite(buzzer, HIGH);
    digitalWrite(relay, LOW);
  }

  else if(eyeState == LOW) {
    digitalWrite(buzzer, HIGH);
  }

  else {
    digitalWrite(buzzer, LOW);
    digitalWrite(relay, HIGH);
  }

  delay(100);
}
