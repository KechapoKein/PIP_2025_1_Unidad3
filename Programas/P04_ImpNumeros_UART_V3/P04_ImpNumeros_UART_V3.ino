void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

byte v=0;

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("valor" + String(v));
  v+=1;
  delay(250);
}
