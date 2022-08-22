/*
 * Autor: Augusto Cesar Becker
 * 
 * Descrição: Funções da Ponte H. Funções de comando da Ponte H, valores de comparação 
 *            em cada função precisam ser calibrados para cada robô.
 */

#include "Ponte_H.h"

void controlar_PonteH(uint8_t pot1,uint8_t pot2, const int in1,const int in2,const int in3,const int in4){
  if (pot2 < 30)
  {
    //Serial.println("Direita");
    PonteH_Direita(in1,in2,in3,in4);
  }
  else if (pot2 > 53) 
  {
    //Serial.println("Esquerda");
    PonteH_Esquerda(in1,in2,in3,in4);
  }
  else if (pot1 < 25)
  {
    //Serial.println("Frente");
    PonteH_Frente(in1,in2,in3,in4);
  }
  else if (pot1 > 50)
  {
    //Serial.println("Tras");
    PonteH_Tras(in1,in2,in3,in4);
  }
  else 
  {
    //Serial.println("Parado");
    PonteH_Parar(in1,in2,in3,in4);
  }
}

void PonteH_Frente(const int in1,const int in2,const int in3,const int in4) {
  digitalWrite(in1, HIGH);
  digitalWrite (in2, LOW);
  digitalWrite(in4, HIGH);
  digitalWrite (in3, LOW);
}

void PonteH_Tras(const int in1,const int in2,const int in3,const int in4) {
  digitalWrite(in2, HIGH);
  digitalWrite (in1, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite (in4, LOW);
}

void PonteH_Direita(const int in1,const int in2,const int in3,const int in4) {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void PonteH_Esquerda(const int in1,const int in2,const int in3,const int in4) {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void PonteH_Parar(const int in1,const int in2,const int in3,const int in4) {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}
