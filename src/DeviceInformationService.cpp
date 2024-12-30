#include "DeviceInformationService.h"
#include <Arduino.h>

DeviceInformationService::DeviceInformationService(const char* deviceName, const char* firmwareVersion)
    : deviceNameCharacteristic(nullptr),
      firmwareVersionCharacteristic(nullptr),
      systemIdCharacteristic(nullptr),
      deviceName(deviceName),
      firmwareVersion(firmwareVersion) {}

void DeviceInformationService::setupService(BLEServer* server) {
    BLEService* deviceInfoService = server->createService(SERVICE_UUID);

    // Gerätenamen-Charakteristik
    deviceNameCharacteristic = deviceInfoService->createCharacteristic(
        DEVICE_NAME_CHAR_UUID,
        BLECharacteristic::PROPERTY_READ
    );
    deviceNameCharacteristic->setValue(deviceName);

    // Firmware-Version-Charakteristik
    firmwareVersionCharacteristic = deviceInfoService->createCharacteristic(
        FIRMWARE_REV_CHAR_UUID,
        BLECharacteristic::PROPERTY_READ
    );
    firmwareVersionCharacteristic->setValue(firmwareVersion);

    // System-ID-Charakteristik (z. B. MAC-Adresse)
    systemIdCharacteristic = deviceInfoService->createCharacteristic(
        SYSTEM_ID_CHAR_UUID,
        BLECharacteristic::PROPERTY_READ
    );
    systemIdCharacteristic->setValue(BLEDevice::getAddress().toString().c_str());

    // Herstellername hinzufügen
    BLECharacteristic* manufacturerCharacteristic = deviceInfoService->createCharacteristic(
        "2A29", // Standard UUID für Manufacturer Name String
        BLECharacteristic::PROPERTY_READ
    );
    manufacturerCharacteristic->setValue("VanVantage");

    deviceInfoService->start();
}