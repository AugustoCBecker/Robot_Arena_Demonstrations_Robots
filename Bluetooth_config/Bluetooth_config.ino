/*
 * Autor: Augusto Cesar Becker
 * 
 * Descrição: Código para configuração do módulo Bluetooth. Os comandos AT são inseridos no Monitor Serial
 *            da IDE do Arduíno e o Arduíno repassa os camandos AT para o módulo Bluetooth.
 */

#include <SoftwareSerial.h>

const SoftwareSerial &BT05 = SoftwareSerial(10, 11);

int led = 13;
int ledHIGH = 0;

unsigned char pot1 = 0;
unsigned char pot2 = 0;

bool connected = false;

long bauds[] = {
  // major
  9600, 57600, 115200,

  // others
  19200, 38400, 4800, 2400, 1200, 230400
};

bool detectBleBaudRate(const SoftwareSerial &BT05) {
  Serial.println("Detecting BLE baud rate:");
  for (int i = 0; i < (sizeof(bauds) / sizeof(long)); i++) {
    Serial.write("Checking ");
    long cur_baud = bauds[i];
    Serial.println(cur_baud, DEC);

    BT05.begin(cur_baud);
    BT05.write("AT\r\n");
    BT05.flush();
    delay(50);
    String response = BT05.readString();
    if (response == "OK\r\n") {
      Serial.println("Detected");
      return true;
    } else {
      BT05.end();
      Serial.print(response.length());
      Serial.println(" chars");
    }
  }
  return false;
}

void readBleData(const SoftwareSerial &BT05, char* str) {
  if (BT05.available()) {
    //Serial.write("ble: ");
    int i = 0;
    while (str[i - 1] != '\n') {
      if (BT05.available()) {
        str[i] = BT05.read();
        i++;
      }
    }
    
    str[i] = '\0';
  }
}

bool verifyConnection(const SoftwareSerial &BT05) {
  char str[10];
  readBleData(BT05, str);
  return (strcmp(str, "AT\r\n") == 0);
  //String aux = str;
  //return (aux == "OK\r\n");
}

void setup() {
  // init
  Serial.begin(115200);

  if (detectBleBaudRate(BT05))
    Serial.write("Ready, type AT commands\n\n");
    else
    Serial.write("Not ready. Halt");

  // Inicializa conexão como o módulo BT05
  BT05.begin(9600);

  pinMode(led, OUTPUT);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
}

void loop() {
  if (BT05.available()) {
      Serial.write("ble: ");
      char str[15];
      int i = 0;
      while (str[i - 1] != '\n') {
        if (BT05.available()) {
          str[i] = BT05.read();
          i++;
        }
      }
      str[i] = '\0';
      Serial.print(str);
      Serial.write('\n');
    }

    // read from USB (Arduino Terminal)
    if (Serial.available()) {
      Serial.write("usb: ");
      char str[15];
      int i = 0;
      while (str[i - 1] != '\n') {
        if (Serial.available()) {
          str[i] = Serial.read();
          i++;
        }
      }
      str[i] = '\0';
      BT05.print(str);
      Serial.print(str);
      Serial.write('\n');
    }
}
