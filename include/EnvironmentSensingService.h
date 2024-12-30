#ifndef ENVIRONMENTSENSINGSERVICE_H
#define ENVIRONMENTSENSINGSERVICE_H

#include <BLEDevice.h>
#include <BLEServer.h>

class EnvironmentSensingService {
public:
    EnvironmentSensingService();
    void setupService(BLEServer* server);
    void updateTemperature(float temperature);
    void updateHumidity(float humidity);

private:
    BLECharacteristic* temperatureCharacteristic;
    BLECharacteristic* humidityCharacteristic;

    static constexpr const char* SERVICE_UUID = "181A"; // Standard Environment Sensing Service
    static constexpr const char* TEMPERATURE_CHAR_UUID = "2A6E"; // Standard Temperature Characteristic
    static constexpr const char* HUMIDITY_CHAR_UUID = "2A6F"; // Standard Humidity Characteristic
};

#endif // ENVIRONMENTSENSINGSERVICE_H