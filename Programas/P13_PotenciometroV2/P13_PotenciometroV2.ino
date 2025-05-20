int pot = A0;//Pin analogico (Sensores)

void setup() {
  // put your setup code here, to run once:👀
  Serial.begin(9600);//No requiere pinMode
}

void loop() {
  // put your main code here, to run repeatedly:👀
  int v = analogRead(pot);
  v = map(v, 0, 1023, 0, 255);
  Serial.println(v);
  delay(100);
}
