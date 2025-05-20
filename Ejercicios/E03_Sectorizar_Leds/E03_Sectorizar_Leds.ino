int index;
int led1 = 7;
int led2 = 8;
int led3 = 9;
int led4 = 10;

void setup() {
  Serial.begin(9600);
  Serial.setTimeout(10);

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
}

void loop() {

  if (Serial.available() > 0) { // Si hay datos en el buffer
    index = Serial.readString().toInt();

    // Si se recibe 0, se ejecuta la secuencia de barrido
    if (index == 0) {
      digitalWrite(led1, 1); delay(200); digitalWrite(led1, 0);
      digitalWrite(led2, 1); delay(200); digitalWrite(led2, 0);
      digitalWrite(led3, 1); delay(200); digitalWrite(led3, 0);
      digitalWrite(led4, 1); delay(200); digitalWrite(led4, 0);

      
      digitalWrite(led4, 1); delay(200); digitalWrite(led4, 0);
      digitalWrite(led3, 1); delay(200); digitalWrite(led3, 0);
      digitalWrite(led2, 1); delay(200); digitalWrite(led2, 0);

    }
    // Si se recibe 1, 2, 3, 4 o 5, se enciende el LED correspondiente
    else {
      digitalWrite(led1, 0);
      digitalWrite(led2, 0);
      digitalWrite(led3, 0);
      digitalWrite(led4, 0);

      
      switch(index) {
        case 1:
          digitalWrite(led1, 1);
          break;
        case 2:
          digitalWrite(led2, 1);
          break;
        case 3:
          digitalWrite(led3, 1);
          break;
        case 4:
          digitalWrite(led4, 1);
          break;

      }
    }
  }
  delay(100);
}