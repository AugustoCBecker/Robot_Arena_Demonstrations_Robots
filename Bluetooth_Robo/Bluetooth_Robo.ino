/*
 * Autor: Augusto Cesar Becker
 * 
 * Descrição: Código do robô. Recebe e interpreta os comandos do controle.
 */

#include <SoftwareSerial.h>
#include "Ponte_H.h"
#include "bluetooth.h"

#define RST_TIME 1000

// Declara as portas usadas para comunicação serial com o módulo BT05
// na forma de uma referência a um objeto
const SoftwareSerial &BT05 = SoftwareSerial(10,11);

// Declara as portas  das entradas da Ponte H
const int in1 = 3;
const int in2 = 5;
const int in3 = 6;
const int in4 = 9;

uint8_t potenciometro1 = 0;    // uint8_t é um int de 8 bits sem sinal
uint8_t potenciometro2 = 0;

char str[30];

bool connected = false;

int t0 = 0; 
int t1 = 0;
void setup() {
  // Inicializa a conexão com o módulo BT05
  BT05.begin(9600);

  // Configura o modo de operação dos pinos do arduino
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  // Garante que todos os pinos estejam em baixo no início da operação do programa
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}

void loop() {
  // Lê os dados recebidos do Bluetooth
  if(connected){
    if (BT05.available()) {
      t0 = millis();
      // Lê os dados recebido do módulo BT05
      readBleData(BT05, str);
      
      // Lê os valores recebidos, caso seja um sinal, sinalizado pela letra 's' no início da mensagem
      if (str[0] == 's'){
        //Serial.println("Funciona!");
        potenciometro1 = (uint8_t) str[1];
        potenciometro2 = (uint8_t) str[2];
      }
  
      // Controla os motores
      controlar_PonteH(potenciometro1,potenciometro2,in1,in2,in3,in4);
    }
  }
  else{
    connected = verifyConnection(BT05);
  }
  
  // Verifica há quanto tempo o bluetooth não recebe dados
  t1 = millis();
  if (t1 - t0 > RST_TIME){
    // Espera por nova conexão caso não receba dados há algum tempo
    connected = false;
    PonteH_Parar(in1,in2,in3,in4);
    t0 = t1;
  }
}
