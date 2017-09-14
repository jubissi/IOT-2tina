const int RELE = 9;

void setup() {
  pinMode(RELE, OUTPUT); //recebe sinal
  Serial.begin(9600); //é a velocidade que o bluetooth trabalha
}

void loop() {
  if (Serial.available()){ //se tiver um caracter disponivel para ler
    char c = Serial.read();
    if(c == 'l'){
      Serial.println("Relê ligado");
      digitalWrite(RELE,HIGH);
    }else if(c == 'd'){
      Serial.println("Relê desligado");
      digitalWrite(RELE,LOW);
    } else {
      Serial.println("Comando inválido");
    }
  }

}
