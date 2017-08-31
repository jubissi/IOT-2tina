#include <SPI.h>
#include <Ethernet.h>

byte mac[] = {0x90, 0xA2, 0xDA, 0x0D, 0x83, 0x11};
IPAddress ip(10, 20, 22, 11); //tambem poderia ser um array de byte
IPAddress gateway(10, 20, 22, 254);
IPAddress subnet(255, 255, 255, 0); //mascara de subrede: identifica/define quantas maquinas e subredes
// no exemplo, 3 primerios redes e ultimo maquina

IPAddress restApi(10, 20, 22, 5);

EthernetClient client;

void setup() {
  Ethernet.begin(mac, ip, gateway, subnet);
  Serial.begin(9600); //velocidade
  Serial.print("Servidor rodando em: ");
  Serial.println(Ethernet.localIP()); //define em qual rede vai rodar

}

void loop() {
  String dado = Serial.readString();
  if (dado != ""){
    String json = "{\"dado\":\"";
    json.concat(dado);
    json.concat("\"}");

    
    if (client.connect(restApi, 3000)){
      client.println("POST /alterar HTTP/1.1");
      client.println("Content-Type: application/json");
      client.println("Host: 10.20.22.5");
      client.println("User-Agent: Arduino/1.0");//navegador
      client.print("Content-Length: ");
      client.println(json.length());

      client.println();

      client.println(json);
      client.stop(); //tem que fechar os recursos porque o arduino é simples e nao executaria depois o loop
      
    }else{
      Serial.println("Nao foi possivel conectar com a API");
    }
    
    Serial.println(json);
  }

}
