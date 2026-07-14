#include "ultrasonic.h"
#include "pins.h"

void Ultrasonic::begin()
{
    pinMode(US_TRIG, OUTPUT);
    pinMode(US_ECHO, INPUT);

    digitalWrite(US_TRIG, LOW);
}

float Ultrasonic::readDistanceCM()
{
    digitalWrite(US_TRIG, LOW);
    delayMicroseconds(2);

    digitalWrite(US_TRIG, HIGH);
    delayMicroseconds(10);
    digitalWrite(US_TRIG, LOW);

    long duration = pulseIn(US_ECHO, HIGH, 30000);

    if (duration == 0)
        return -1;

    return duration * 0.0343f / 2.0f;
}