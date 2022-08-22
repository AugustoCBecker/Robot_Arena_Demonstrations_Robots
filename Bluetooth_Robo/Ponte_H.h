#ifndef PONTEH_H
#define PONTEH_H

#include <Arduino.h>

void controlar_PonteH(uint8_t pot1,uint8_t pot2,const int in1,const int in2,const int in3,const int in4);

void PonteH_Frente(const int in1,const int in2,const int in3,const int in4);
void PonteH_Tras(const int in1,const int in2,const int in3,const int in4);
void PonteH_Direita(const int in1,const int in2,const int in3,const int in4);
void PonteH_Esquerda(const int in1,const int in2,const int in3,const int in4);
void PonteH_Parar(const int in1,const int in2,const int in3,const int in4);


#endif
