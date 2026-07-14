#pragma once

#include <Arduino.h>

class Ultrasonic
{
public:
    void begin();
    float readDistanceCM();
};