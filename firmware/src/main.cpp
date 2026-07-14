#include <Arduino.h>

#include "motor.h"
#include "ir_sensor.h"

MotorController motor;
IRSensor ir;

void setup()
{
    Serial.begin(115200);

    motor.begin();
    ir.begin();

    Serial.println("AIRena Robot Initialized");
}

void loop()
{
    Serial.print("L: ");
    Serial.print(ir.left());

    Serial.print(" C: ");
    Serial.print(ir.center());

    Serial.print(" R: ");
    Serial.println(ir.right());

    delay(500);
}