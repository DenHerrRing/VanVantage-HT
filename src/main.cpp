#include <Arduino.h>
#include <BLEDevice.h>
#include <BLEServer.h>
#include "EnvironmentSensingService.h"
#include "BatteryService.h"
#include "DeviceInformationService.h"
#include "RandomGenerator.h"

EnvironmentSensingService envService;
BatteryService batteryService;
DeviceInformationService deviceInfoService("T&H Modul", "1.0.0");
RandomGenerator randomGen;

void setup() {
    Serial.begin(115200);
    BLEDevice::init("T&H Modul"); // Initialisierung des BLE-Stacks
    BLEDevice::setMTU(512); // MTU-Größe erhöhen, um größere Datenmengen zu unterstützen

    // Zu Testzwecke!
    // BLEDevice::setSecurityCallbacks(nullptr); // Deaktiviert Sicherheitsanforderungen
    // BLEDevice::setEncryptionLevel(ESP_BLE_SEC_ENCRYPT_NO_MITM); // Keine Verschlüsselung erforderlich

    BLEServer* server = BLEDevice::createServer();

    server->getAdvertising()->setMinPreferred(0x06); // Minimal zulässige Verbindungseinstellungen
    server->getAdvertising()->setMaxPreferred(0x12); // Maximale Verbindungseinstellungen

    // Services einrichten
    envService.setupService(server);
    batteryService.setupService(server);
    deviceInfoService.setupService(server);

    // BLE-Werbung starten
    BLEAdvertising* advertising = BLEDevice::getAdvertising();
    advertising->setScanResponse(true); // Aktiviert den Namen in der Werbung
    advertising->start();

    Serial.println("T&H Modul gestartet und Werbung aktiv.");
}

void loop() {
    // Beispielhafte zufällige Werte generieren
    float randomTemperature = randomGen.generateFloat(20.0, 35.0); // Temperatur zwischen 20.0 und 35.0 °C
    float randomHumidity = randomGen.generateFloat(30.0, 70.0);    // Luftfeuchtigkeit zwischen 30.0 und 70.0 %
    uint8_t randomBatteryLevel = randomGen.generateUint8(50, 100); // Batteriestand zwischen 50% und 100%

    envService.updateTemperature(randomTemperature);
    envService.updateHumidity(randomHumidity);
    batteryService.updateBatteryLevel(randomBatteryLevel);

    // Werte zur Debugging-Ausgabe
    Serial.printf("Aktualisierte Werte: Temperatur = %.1f °C, Luftfeuchtigkeit = %.1f %%, Batterie = %d%%\n", 
                  randomTemperature, randomHumidity, randomBatteryLevel);

    delay(10000); // Aktualisierung alle 10 Sekunden
}