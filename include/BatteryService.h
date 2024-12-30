#ifndef BATTERYSERVICE_H
#define BATTERYSERVICE_H

#include <BLEDevice.h>
#include <BLEServer.h>

class BatteryService {
public:
    BatteryService();
    void setupService(BLEServer* server);
    void updateBatteryLevel(uint8_t level);

private:
    BLECharacteristic* batteryLevelCharacteristic;

    static constexpr const char* SERVICE_UUID = "180F"; // Standard Battery Service
    static constexpr const char* BATTERY_LEVEL_CHAR_UUID = "2A19"; // Standard Battery Level Characteristic
};

#endif // BATTERYSERVICE_H