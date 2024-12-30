#ifndef RANDOMGENERATOR_H
#define RANDOMGENERATOR_H

#include <Arduino.h>

class RandomGenerator {
public:
    RandomGenerator();

    float generateFloat(float min, float max);
    uint8_t generateUint8(uint8_t min, uint8_t max);

private:
    void seed();
};

#endif // RANDOMGENERATOR_H
