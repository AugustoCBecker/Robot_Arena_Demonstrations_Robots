#ifndef BLUETOOTH_H
#define BLUETOOTH_H

#include <Arduino.h>
#include <string.h>
#include <SoftwareSerial.h>

// Detecta o baud rate do módulo BT05, usar apenas para debug
bool detectBleBaudRate(const SoftwareSerial &BT05);

// Retransmite os dados da porta serial para o módulo BT05
void retransmitSerialCommand(const SoftwareSerial &BT05);

// Lê os dados recebidos pelo módulo BT05
void readBleData(const SoftwareSerial &BT05, char* str);

// Verifica se a conexão com o bluetooth já foi efetuada
bool verifyConnection(const SoftwareSerial &BT05);
#endif
