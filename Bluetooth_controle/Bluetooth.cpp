#include "Bluetooth.h" 

static long bauds[] = {
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
  char str[10] = {0};
  readBleData(BT05, str);
  
  return (strcmp(str, "AT\r\n") == 0);
}
