# Robot_Arena_Demonstrations_Robots
Conjunto de códigos Arduino usados para configurar módulos Bluetooth, configurar os controles usados no projeto e controlar os robôs.

## Projeto "Bluetooth_config"
  - Código para o Arduíno Uno/Nano, usado para transmitir ao módulo Bluetooth os comandos AT enviados ao Arduíno pelo terminal da IDE são utilizados os comandos AT para configurar o módulo instalado no controle em modo mestre, e fazê-lo conectar de forma automática ao módulo instalado no Robô.
  
## Projeto "Bluetooth_Robo"
  - Código para o Arduíno Uno/Nano instalado no Robô, responsável por ler as informações recebidas pelo módulo Bluetooth e, a partir delas, controlar a(s) Ponte(s) H.

## Projeto "Bluetooth_controle"
  - Código para o Arduíno Uno/Nano instalado no controle, responsável por ler os níveis de tensão nos potenciômetros ligados aos joysticks e transmitir os dados coletados ao módulo Bluetooth, responsável por retransmitir esses dados ao módulo instalado no Robô.
