#include "BatteryService.h"

BatteryService::BatteryService() : batteryLevelCharacteristic(nullptr) {}

void BatteryService::setupService(BLEServer* server) {
    BLEService* batteryService = server->createService(SERVICE_UUID);

    // Batterie-Level-Charakteristik
    batteryLevelCharacteristic = batteryService->createCharacteristic(
        BATTERY_LEVEL_CHAR_UUID,
        BLECharacteristic::PROPERTY_READ | BLECharacteristic::PROPERTY_NOTIFY
    );

    int initialBatteryLevel = 100; // Initialer Wert: 100%
    batteryLevelCharacteristic->setValue(std::to_string(initialBatteryLevel));

    batteryService->start();
}

void BatteryService::updateBatteryLevel(uint8_t level) {
    if (batteryLevelCharacteristic) {
        uint8_t batteryLevel = level; // Lokale Variable vom Typ uint8_t
        batteryLevelCharacteristic->setValue(std::to_string(batteryLevel));
        batteryLevelCharacteristic->notify();
    }
}