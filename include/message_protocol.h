#ifndef __MESSAGE_PROTOCOL_H
#define __MESSAGE_PROTOCOL_H

#include <Arduino.h>
#define MESSAGE_LEN 11
#define MEX_HEADER 0x30
#define REQ_PKT_HEADER 0x0a
#define ACK 0x00
#define SENSOR_TYPE 0x03
#define PIR_POS 0x05
#define FROM_PIR_TO_PIR_OFFSET 0x08
#define ALARM_ON 0x01
#define RECEIVING_STR "Receiving byte n° %u\n"

bool checkPIR(const uint8_t *message, uint8_t len);

#endif