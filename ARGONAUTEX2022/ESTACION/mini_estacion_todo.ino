//Estacion de tierra

//Librerias
#include <SPI.h>
#include <LoRa.h>

//Declaracion de varibales
const long frequency = 868E6;
int num = 0;
int h = 0;
int contador;
String datos[15];
String all;
String prov;

void setup() {
  //Iniciamos serial
  Serial.begin(9600);
  //LoRa
  if (!LoRa.begin(frequency)) {
    Serial.println("LoRa init failed. Check your connections.");
    while (true);
  }
  LoRa.onReceive(onReceive);
  LoRa_rxMode();
}

void loop() {
  //Funcion para recibir los datos

}

//Funciones de LoRa
void LoRa_rxMode() {
  LoRa.disableInvertIQ();
  LoRa.receive();
}

void onReceive(int packetSize) {
  String message = "";

  while (LoRa.available()) {
    message += (char)LoRa.read();
  }

  Serial.println(message);
}

void onTxDone() {
  Serial.println("TxDone");
  LoRa_rxMode();
}
