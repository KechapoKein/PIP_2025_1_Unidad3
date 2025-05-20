int led = 13;

void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);//Puede ser Output (Actuadores digitales) o Input
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(led, 1);//1 = Alto/High, 0 = Bajo/Low
  digitalWrite(led, 0);
}
