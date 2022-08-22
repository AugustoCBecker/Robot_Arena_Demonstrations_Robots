#ifndef BLUETOOTH_H
#define BLUETOOTH_H

#include <SoftwareSerial.h>
#include <Arduino.h>

// Função de testes para detectar a configuração de taxa de bits por segundo do módulo BT05
bool detectBleBaudRate(const SoftwareSerial &BT05);

// Função de leitura dos dados do módulo BT05 usando o protocolo de comunicação estabelecido neste projeto (terminar as strings com "\r\n")
void readBleData(const SoftwareSerial &BT05, char* str);

// Função para verificar se o módulo BT05 está conectado ao seu par
bool verifyConnection(const SoftwareSerial &BT05);

#endif    //ifndef BLUETOOTH_H
