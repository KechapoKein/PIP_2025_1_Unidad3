void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);//baudios
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("hola mundo");
  delay(100);//ms
}
