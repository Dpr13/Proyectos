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
    Serial.println("Error al inicial LoRa");
    while (true);
  }
  LoRa.onReceive(onReceive);
  LoRa_rxMode();
}

void loop() {
  Serial.println(all);
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
  all = "";
  for (int h = 0; h < message.length(); h++) {
    if (message[h] != ',') {
      prov = prov + message[h];
    } else if (message[h] == ',') {
      datos[contador] = prov;
      prov = "";
      contador ++;
    }
  }
  all += datos[12].toInt();
  all += ",";
  all += String(37 + (((datos[10].toFloat()/100.0)-37.0)/60.0)*100,5);
  all += ",";
  all += String(3 + (((datos[11].toFloat()/100.0)-3.0)/60.0)*100,5);
  prov = "";
  contador = 0;
}

void onTxDone() {
  Serial.println("TxDone");
  LoRa_rxMode();
}
