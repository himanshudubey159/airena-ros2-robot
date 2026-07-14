#pragma once

#include <Arduino.h>

class IRSensor
{
public:
    void begin();

    bool left() const;
    bool center() const;
    bool right() const;

private:
    bool readPin(uint8_t pin) const;
};