const int ledPins[8] = {2,3,4,5,6,7,8,9};

void setup(){
  Serial.begin(9600);
  for (int i = 0; i < 8; i++) {
    pinMode(ledPins[i],OUTPUT);
  }
}

void loop(){
  if(Serial.available()>0){
    int numero = Serial.parseInt();
    if(numero>=0 && numero <= 255){
      mostrarBinario(numero);
      delay(4500);
      apagarLeds();
    }
    else{
      Serial.println("Número fuera de rango (0-255)");
    }
  }
}

void mostrarBinario(int num){
  for(int i = 0; i < 8; i++){
    digitalWrite(ledPins[i], (num >> i)&1);
  }
}

void apagarLeds(){
  for (int i = 0; i < 8; i++) {
    digitalWrite(ledPins[i],LOW);
  }
}