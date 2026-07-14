#include "ir_sensor.h"
#include "pins.h"

void IRSensor::begin()
{
    pinMode(IR_LEFT, INPUT);
    pinMode(IR_CENTER, INPUT);
    pinMode(IR_RIGHT, INPUT);
}

bool IRSensor::readPin(uint8_t pin) const
{
    return digitalRead(pin);
}

bool IRSensor::left() const
{
    return readPin(IR_LEFT);
}

bool IRSensor::center() const
{
    return readPin(IR_CENTER);
}

bool IRSensor::right() const
{
    return readPin(IR_RIGHT);
}