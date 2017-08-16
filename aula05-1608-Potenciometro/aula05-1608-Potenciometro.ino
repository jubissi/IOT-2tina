const int POT = A3;
const int LED = 9;

void setup() {
  pinMode(POT, INPUT);
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int valor = analogRead(POT)/4;
  Serial.println(valor);
  analogWrite(LED, valor);
}
