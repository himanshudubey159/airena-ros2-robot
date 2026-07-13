#include <Arduino.h>
#include "motor.h"

MotorController motor;

void setup()
{
    Serial.begin(115200);

    Serial.println("AIRena Robot Booting...");

    motor.begin();

    Serial.println("Motor controller initialized.");
}

void loop()
{
    delay(1000);
}