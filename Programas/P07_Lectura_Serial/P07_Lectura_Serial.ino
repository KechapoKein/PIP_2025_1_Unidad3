String resp;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()>0){
    resp=Serial.readString();//timeout default= 1 seg
    Serial.println(resp);
  }
  delay(100);
}
