//NOTE: at the moment this is only a test code
#include <wifi_connection.h>
#include <common.h>
#include <message_protocol.h>

WiFiClient wifiClient;

void setup() {
  Serial.begin(SERIAL_BAUD);
  pinMode(COM_LED_PIN, OUTPUT);
  pinMode(ALARM_LED_PIN, OUTPUT);
  WiFiConnection wifiConnection(SSID, PASSPHRASE);
 
  if (!wifiConnection.tryConnection()) {
    Serial.println(WIFI_CON_ERR);
    ESP.restart();
  }

  if (wifiClient.connect(ALARM_SERVER_IP, ALARM_SERVER_PORT)) {
    Serial.println(CON_SERVER_OK);
  } else {
    Serial.println(CON_SERVER_KO);
  }

  wifiClient.write(REQ_PKT_HEADER);
  while (!wifiClient.available());
  
  if (wifiClient.read() == ACK) {
    Serial.println(ACK_RECEIVED);
  } else {
    Serial.println(NACK_RECEIVER);
  }
}

void loop() {
  uint8_t len = 0;
  uint8_t data[200];
  if (wifiClient.available()) {
    digitalWrite(COM_LED_PIN, HIGH);
    while (wifiClient.available()) {
      data[len++] = wifiClient.read();
      Serial.printf(RECEIVING_STR, len);
    }
    digitalWrite(COM_LED_PIN, LOW);
    wifiClient.write((byte)ACK);
  }

  if (len > 0) {
    if (checkPIR(data, len)) {
      while (true) {
        digitalWrite(ALARM_LED_PIN, HIGH);
        delay(ALARM_DELAY);
        digitalWrite(ALARM_LED_PIN, LOW);
        delay(ALARM_DELAY);
      }
    }
  }
}