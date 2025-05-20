int led1 = 10;
int led2 = 9;
int led3 = 8;
int led4 = 7;

void setup() {
  // put your setup code here, to run once:
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  Serial.begin(9600);
  Serial.setTimeout(10);
}

int v;

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available()>0) {
    v=Serial.readString().toInt();
    digitalWrite(led1, v);
  }

  delay(100);
}
