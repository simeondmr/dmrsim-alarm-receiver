#ifndef __COMMON_H
#define __COMMON_H

#include <Arduino.h>
#define SERIAL_BAUD 9600
#define COM_LED_PIN 27
#define ALARM_LED_PIN 26
#define ALARM_SERVER_IP "192.168.1.11"
#define ALARM_SERVER_PORT 10004
#define CON_SERVER_OK "Connected to alarm server"
#define CON_SERVER_KO "Fail to connect to alarm server"
#define ACK_RECEIVED "ACK received"
#define NACK_RECEIVER "NACK receiver"
#define ALARM_DELAY 1000

#endif