/*
 * Autor: Augusto Cesar Becker
 * 
 * Descrição: Código do controle. Lê os valores dos potênciometros e transmite ao módulo BLE (Bluettoth Low Energy)
 *            A conexão entre os módulos Bluetooth é feita de forma automática pelos módulos.
 *            A configuração dos módulos BLE é feita através de comandos AT, no caso foi utilizado o comando AT+BAND<MAC>
 *            para determinar qual o endereço MAC que cada módulo Bluetooth deve procurar e se conectar.
 */

#include <SoftwareSerial.h>
#include "Bluetooth.h"

const SoftwareSerial &BT05 = SoftwareSerial(10, 11);

int led = 13;

unsigned char pot1 = 0;
unsigned char pot2 = 0;

bool connected = false;


void setup() {
  // Inicializa a conexão com o módulo BT05
  BT05.begin(9600);

  pinMode(led, OUTPUT);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
}

void loop() {
  if (connected) {
    // Armazena os valores lidos dos potênciometros (em um range de 0~255)
    pot1 = (char)(analogRead(A0) / 4);    
    pot2 = (char)(analogRead(A1) / 4);
    delay(20);

    // Envia os dados para o módulo Bluetooth
    char pots[5] = {0}; // Inicializa o vetor que irá conter os dados
    pots[0] = 's';      // Byte sinalizando que o array de dados representa um sinal com os dados do potênciometro
    pots[1] = pot1;     // Byte com a leitura do primeiro potênciometro
    pots[2] = pot2;     // Byte com a leitura do segundo potênciometro
    pots[3] = '\r';     // Bytes representando o fim do array de dados
    pots[4] = '\n';
    pots[5] = '\0';
    BT05.print(pots);
    
  } else {
    connected = verifyConnection(BT05);
  }
}
