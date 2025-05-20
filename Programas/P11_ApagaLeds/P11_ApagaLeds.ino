int led1 = 10;
int led2 = 9;
int led3 = 8;
int led4 = 7;
int v;

void setup() {
  // put your setup code here, to run once:
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  Serial.begin(9600);
  Serial.setTimeout(10);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available()>0) {
    v=Serial.readString().toInt();
    digitalWrite(led1,0);
    digitalWrite(led2,0);
    digitalWrite(led3,0);
    digitalWrite(led4,0);

    switch (v) {
    case 1:
     digitalWrite(led1, v);
     break;
    case 2:
    digitalWrite(led2, v);
     break;
    case 3:
     digitalWrite(led3, v);
     break;
    case 4:
    digitalWrite(led4, v);
     break;

    }
      }

  delay(100);
}

