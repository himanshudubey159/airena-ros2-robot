#pragma once

#include "motor.h"
#include "ir_sensor.h"

class LineFollower
{
public:
    LineFollower(MotorController &motor, IRSensor &ir);

    void update();

private:
    MotorController &motor;
    IRSensor &ir;

    const uint8_t SPEED = 180;
};