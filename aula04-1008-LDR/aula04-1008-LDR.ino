const int LDR = A0;
const int LED = 13;

void setup() {
  pinMode(LDR, INPUT); //LDR: foto resistor
  pinMode(LED, OUTPUT); 
  Serial.begin(9600); //serial é o protocolo para comunicar
}

void loop() {
  int valor = analogRead(LDR);

  Serial.println(valor);
  if(valor < 60){
    digitalWrite(LED, HIGH);
  }else{
    digitalWrite(LED, LOW);
  }
}
