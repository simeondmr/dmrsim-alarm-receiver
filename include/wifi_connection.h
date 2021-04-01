#ifndef __WIFI_CONNECTION_H
#define __WIFI_CONNECTION_H

#include <WiFi.h>
#define DELAY_CON 2000
#define MAX_RETRY 10
#define TRY_CON_STR "Try connection to WiFi, attempt: %u\n"
#define CON_SUCCESSFULLY_STR "Connection successfully"
#define WIFI_CON_ERR "Error wifi connection, reboot"
#define SSID "****"
#define PASSPHRASE "****"

class WiFiConnection {
private:
    const char *ssid;
    const char *passphrase;
public:
    WiFiConnection(const char *ssid, const char *passphrase) {
        this->ssid = ssid;
        this->passphrase = passphrase;
    }

    bool tryConnection();
};

#endif