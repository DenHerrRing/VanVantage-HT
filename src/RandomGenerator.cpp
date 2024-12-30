#include "RandomGenerator.h"
#include <Arduino.h>

RandomGenerator::RandomGenerator() {
    seed();
}

void RandomGenerator::seed() {
    randomSeed(millis()); // Initialisiere den Zufallszahlengenerator mit der aktuellen Zeit
}

float RandomGenerator::generateFloat(float min, float max) {
    return min + static_cast<float>(random(10000)) / 10000.0 * (max - min);
}

uint8_t RandomGenerator::generateUint8(uint8_t min, uint8_t max) {
    return random(min, max + 1); // Erzeuge eine Zufallszahl im Bereich [min, max]
}
