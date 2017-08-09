const int LED = 8; //variável int (numero da porta), const porque nao vamos mudar ela

void setup() {
  pinMode(LED, OUTPUT); //indica o tipo de porta, no caso porta 8 saída
}

void loop() {
  //enquanto estiver desligado na energia a logica sera executada
  digitalWrite(LED, LOW); //porta digital, lendo de forma digital (0 e 1), iniciando desligado (LOW)
  delay(1000); //em ms
  digitalWrite(LED, HIGH); //ligado
  delay(1000);
}

//indicar qual placa estamos trabalhando: Tools > Board
//verificar se a porta está ativada: Tools > Port
