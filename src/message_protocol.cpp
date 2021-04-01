#include <message_protocol.h>

/**
 * Message segment:
 * Header:       1 byte
 * Time:         4 byte
 * Sensor type:  1 byte
 * Alarm status: 1 byte
 * Sensor value: 2 byte
 */
bool checkPIR(const uint8_t *message, uint8_t len) {
    uint8_t i = PIR_POS;
    while (i < len) {
        if (message[i] == SENSOR_TYPE && message[i + 1] == ALARM_ON) {
            return true;
        }
        i += FROM_PIR_TO_PIR_OFFSET;
    }
    return false;
}