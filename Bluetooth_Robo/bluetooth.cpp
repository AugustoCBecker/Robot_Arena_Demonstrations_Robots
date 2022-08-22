#include "bluetooth.h"

bool detectBleBaudRate(const SoftwareSerial &BT05) {
  long bauds[] = {
  // major
  9600, 57600, 115200,

  // others
  19200, 38400, 4800, 2400, 1200, 230400
  };
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
      Serial.print(response.length());
      Serial.println(" chars");
      return true;
    } else {
      BT05.end();
      Serial.print(response.length());
      Serial.println(" chars");
    }
  }
  return false;
}

void retransmitSerialCommand(const SoftwareSerial &BT05){
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

void readBleData(const SoftwareSerial &BT05, char* str){
  if (BT05.available()) {
    //Serial.write("ble: ");
    int i = 0;
    while (str[i - 1] != '\n' || str[i - 2] != '\r' || i < 3) {
      if (BT05.available()) {
        str[i] = BT05.read();
        i++;
      }
    }
    
    str[i] = '\0';
  }
}

bool verifyConnection(const SoftwareSerial &BT05){
  BT05.print("AT\r\n");
  delay(50);
  char str[10];
  
  readBleData(BT05,str);
  return (strcmp(str,"OK\r\n") != 0);
}
