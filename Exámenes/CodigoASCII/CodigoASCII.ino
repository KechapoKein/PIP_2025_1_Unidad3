const int ledPins[8] = {2,3,4,5,6,7,8,9};
char palabra[6];
bool Mayus = true;

void setup(){
  Serial.begin(9600);
  for(int i = 0; i < 8; i++){
    pinMode(ledPins[i],OUTPUT);
  }
}

void loop(){
  if(Serial.available()>0){
    int len = Serial.readBytesUntil('\n',palabra,5);
    palabra[len] = '\0';

    if(Mayus){
      for(int i = 0; i < len; i++){
        palabra[i] = toupper(palabra[i]);
      }
    }else{
      for(int i = 0; i < len; i++){
        palabra[i] = tolower(palabra[i]);
      }
    }

    for(int i = 0; i < len; i++){
      mostrarBinario(palabra[i]);
      delay(5000);
      apagarLeds();
      delay(1000);
    }
  }
}

void mostrarBinario(int num){
  int binario[8];

  for(int i = 0; i < 8; i++){
    binario[i] = num % 2;
    num = num / 2;
  }

  for(int i = 0; i < 8; i++){
    digitalWrite(ledPins[i], binario[i]);
  }
}

void apagarLeds(){
  for(int i = 0; i < 8; i++){
    digitalWrite(ledPins[i], LOW);
  }
}