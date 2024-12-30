#include "EnvironmentSensingService.h"
#include <Arduino.h> // Für snprintf

EnvironmentSensingService::EnvironmentSensingService()
    : temperatureCharacteristic(nullptr), humidityCharacteristic(nullptr) {}

void EnvironmentSensingService::setupService(BLEServer* server) {
    BLEService* envService = server->createService(SERVICE_UUID);

    // Temperatur-Charakteristik
    temperatureCharacteristic = envService->createCharacteristic(
        TEMPERATURE_CHAR_UUID,
        BLECharacteristic::PROPERTY_READ | BLECharacteristic::PROPERTY_NOTIFY
    );
    temperatureCharacteristic->setValue("0.0");

    // Luftfeuchtigkeits-Charakteristik
    humidityCharacteristic = envService->createCharacteristic(
        HUMIDITY_CHAR_UUID,
        BLECharacteristic::PROPERTY_READ | BLECharacteristic::PROPERTY_NOTIFY
    );
    humidityCharacteristic->setValue("0.0");

    envService->start();
}

void EnvironmentSensingService::updateTemperature(float temperature) {
    if (temperatureCharacteristic) {
        char tempStr[8];
        snprintf(tempStr, sizeof(tempStr), "%.1f", temperature);
        temperatureCharacteristic->setValue(tempStr);
        temperatureCharacteristic->notify();
    }
}

void EnvironmentSensingService::updateHumidity(float humidity) {
    if (humidityCharacteristic) {
        char humStr[8];
        snprintf(humStr, sizeof(humStr), "%.1f", humidity);
        humidityCharacteristic->setValue(humStr);
        humidityCharacteristic->notify();
    }
}