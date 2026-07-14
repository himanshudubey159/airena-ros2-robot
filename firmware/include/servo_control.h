#pragma once

#include <Arduino.h>
#include <ESP32Servo.h>

class ServoControl
{
public:
    void begin();

    void center();
    void left();
    void right();

    void setAngle(uint8_t angle);

private:
    Servo servo;
};