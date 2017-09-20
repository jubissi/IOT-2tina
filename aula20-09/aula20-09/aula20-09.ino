#include <SPI.h>
#include <Ethernet.h>
#include <PubSubClient.h>

byte mac[] = {0xDE, 0xED, 0xBA, 0xFE, 0xFE, 0x11};
IPAddress ip(10, 20, 22, 11);
IPAddress server(10, 20, 22, 100);

const int LED = 9;
EthernetClient ethClient;
PubSubClient client(ethClient);

void callback(char* topic, byte* payload, unsigned int length) {
  String msg = "";
  Serial.println(topic);
  Serial.println();

  for (int i=0; i < length; i++) {
    msg.concat((char)payload[i]);
  }

  Serial.println(msg);
  if (msg == "ligar") {
    digitalWrite(LED, HIGH);
  }else if(msg == "desligar"){
    digitalWrite(LED, LOW);
  }
}

void reconnect() {
  while (!client.connected()) {
    Serial.println("Tentanto se conectar com o broker");
    if (client.connect("Arduino11")) {
      Serial.println("Conectado com sucesso");
      client.publish("tina2", "Arduino11 conectado!");
      client.subscribe("tina2");
    }else{
      Serial.println("Não foi possível se conectar ao MQTT Broker");
    }
  }
}

void setup() {
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
  
  client.setServer(server, 1883);
  client.setCallback(callback);

  Ethernet.begin(mac, ip);
  delay(1500);

  Serial.println(Ethernet.localIP());
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

}
