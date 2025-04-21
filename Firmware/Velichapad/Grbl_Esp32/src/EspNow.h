#pragma once


// #ifndef ESPNOW_H
// #define ESPNOW_H

#include <esp_now.h>
#include <WiFi.h>

class EspNow {
public:
    EspNow(const uint8_t* peerMac);
    void begin();
    void send(int number);

private:
    uint8_t peerAddress[6];
    static void onDataSent(const uint8_t *mac_addr, esp_now_send_status_t status);
};


