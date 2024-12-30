#ifndef DEVICEINFORMATIONSERVICE_H
#define DEVICEINFORMATIONSERVICE_H

#include <BLEDevice.h>
#include <BLEServer.h>

class DeviceInformationService {
public:
    DeviceInformationService(const char* deviceName, const char* firmwareVersion);
    void setupService(BLEServer* server);

private:
    BLECharacteristic* deviceNameCharacteristic;
    BLECharacteristic* firmwareVersionCharacteristic;
    BLECharacteristic* systemIdCharacteristic;
    BLECharacteristic* manufacturerCharacteristic;

    static constexpr const char* SERVICE_UUID = "180A"; // Standard Device Information Service
    static constexpr const char* DEVICE_NAME_CHAR_UUID = "2A00"; // Standard Device Name Characteristic
    static constexpr const char* FIRMWARE_REV_CHAR_UUID = "2A26"; // Standard Firmware Revision Characteristic
    static constexpr const char* SYSTEM_ID_CHAR_UUID = "2A23"; // Standard System ID Characteristic
    static constexpr const char* MANUFACTURER_NAME_CHAR_UUID = "2A29"; // Standard Manufacturer Name Characteristic

    const char* deviceName;
    const char* firmwareVersion;
};

#endif // DEVICEINFORMATIONSERVICE_H
