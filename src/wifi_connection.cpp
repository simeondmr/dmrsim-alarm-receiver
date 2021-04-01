#include <wifi_connection.h>
#include <WiFi.h>
#include <common.h>

bool WiFiConnection::tryConnection() {
    for (uint8_t i = 1;i <= MAX_RETRY;i++) {
        Serial.printf(TRY_CON_STR, i);
        wl_status_t status = WiFi.begin(this->ssid, this->passphrase);
        delay(DELAY_CON);
        if (status == WL_CONNECTED) {
            return true;
        }
    }
    return false;
}