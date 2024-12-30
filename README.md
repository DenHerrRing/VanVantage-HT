# H&T Modul - Temperatur- und Luftfeuchtigkeitssensor

Das **H&T Modul** ist ein BLE-fähiges Modul, das Temperatur- und Luftfeuchtigkeitswerte misst und über Bluetooth Low Energy (BLE) bereitstellt. Zusätzlich liefert es den Batteriestand des Moduls und grundlegende Geräteinformationen wie Gerätename, Firmware-Version und Hersteller.

---

## Features

- **Temperaturmessung:** Bereich von 20.0°C bis 35.0°C
- **Luftfeuchtigkeitsmessung:** Bereich von 30.0% bis 70.0%
- **Batterieanzeige:** Batteriestand in Prozent (0% bis 100%)
- **Geräteinformationen:**
  - Gerätename
  - Firmware-Version
  - Herstellerinformationen

---

## Installation

### Voraussetzungen

- **Hardware:** ESP32
- **Software:**
  - [PlatformIO](https://platformio.org/) in VSCode
  - Arduino-Framework für ESP32

### Schritte

1. **Repository klonen:**
   ```bash
   git clone https://github.com/dein-repo-url/ht-modul.git
   cd ht-modul
   ```

2. **Abhängigkeiten installieren:**
   PlatformIO installiert alle erforderlichen Bibliotheken automatisch basierend auf der `platformio.ini`.

3. **Projekt auf das ESP32-Board flashen:**
   ```bash
   pio run --target upload
   ```

4. **Serielle Ausgabe überprüfen:**
   Öffne den seriellen Monitor:
   ```bash
   pio device monitor
   ```

---

## Module

### 1. Environment Sensing Service
- **UUID:** `0x181A`
- **Charakteristiken:**
  - **Temperatur:** `0x2A6E`
  - **Luftfeuchtigkeit:** `0x2A6F`

### 2. Battery Service
- **UUID:** `0x180F`
- **Charakteristiken:**
  - **Batteriestand:** `0x2A19`

### 3. Device Information Service
- **UUID:** `0x180A`
- **Charakteristiken:**
  - **Gerätename:** `0x2A00`
  - **Firmware-Version:** `0x2A26`
  - **System-ID:** `0x2A23`
  - **Herstellername:** `0x2A29`

---

## Nutzung

### Verbindung herstellen
1. Öffne eine BLE-App wie **nRF Connect** oder **LightBlue Explorer**.
2. Suche nach dem Gerät mit dem Namen `T&H Modul`.
3. Verbinde dich mit dem Gerät.

### Daten abrufen
- **Temperatur und Luftfeuchtigkeit:**
  - Gehe zu den Charakteristiken des `Environment Sensing Service` und aktiviere Benachrichtigungen, um Echtzeitdaten zu erhalten.
- **Batteriestand:**
  - Lies die Batteriestand-Charakteristik des `Battery Service`.
- **Geräteinformationen:**
  - Lies die Charakteristiken im `Device Information Service`, z. B. Firmware-Version und Herstellername.

---

## Debugging
- Verwende den seriellen Monitor, um Debugging-Informationen zu sehen:
  - Aktualisierte Temperatur-, Luftfeuchtigkeits- und Batteriestandwerte.
  - Status der BLE-Werbung und Verbindung.

---

## Lizenz
Dieses Projekt steht unter der [MIT-Lizenz](LICENSE).
