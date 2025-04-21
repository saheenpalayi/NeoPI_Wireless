#include "EspNow.h"

EspNow::EspNow(const uint8_t* peerMac) {
    memcpy(peerAddress, peerMac, 6);
}

void EspNow::begin() {
    WiFi.mode(WIFI_STA);
    if (esp_now_init() != ESP_OK) {
        Serial.println("Error initializing ESP-NOW");
        return;
    }

    esp_now_register_send_cb(onDataSent);

    esp_now_peer_info_t peerInfo = {};
    memcpy(peerInfo.peer_addr, peerAddress, 6);
    peerInfo.channel = 0;
    peerInfo.encrypt = false;

    if (!esp_now_is_peer_exist(peerAddress)) {
        if (esp_now_add_peer(&peerInfo) != ESP_OK) {
            Serial.println("Failed to add peer");
            return;
        }
    }
}

void EspNow::send(int number) {
    esp_err_t result = esp_now_send(peerAddress, (uint8_t*)&number, sizeof(number));
    if (result != ESP_OK) {
        Serial.println("Failed to send message");
    }
}

void EspNow::onDataSent(const uint8_t *mac_addr, esp_now_send_status_t status) {
    Serial.print("Send Status: ");
    Serial.println(status == ESP_NOW_SEND_SUCCESS ? "Success" : "Fail");
}
