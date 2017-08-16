const int BTN = 2;
const int LED = 4;

void setup() {
  pinMode(BTN, INPUT);
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int ligado = digitalRead(BTN);
  if(ligado == HIGH){ //HIGH = 5V
    Serial.println("Ligado");
    digitalWrite(LED, HIGH);
  }else{
    Serial.println("Desligado");
    digitalWrite(LED, LOW);
  }

}
