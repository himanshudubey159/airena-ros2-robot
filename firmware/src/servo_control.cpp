#include "servo_control.h"
#include "pins.h"

void ServoControl::begin()
{
    servo.attach(SERVO_PIN);
    center();
}

void ServoControl::setAngle(uint8_t angle)
{
    angle = constrain(angle, 0, 180);
    servo.write(angle);
}

void ServoControl::center()
{
    setAngle(90);
}

void ServoControl::left()
{
    setAngle(150);
}

void ServoControl::right()
{
    setAngle(30);
}