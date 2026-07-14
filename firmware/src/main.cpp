#include <Arduino.h>

#include "motor.h"
#include "ir_sensor.h"
#include "ultrasonic.h"

MotorController motor;
IRSensor ir;
Ultrasonic ultrasonic;

void setup()
{
    Serial.begin(115200);

    motor.begin();
    ir.begin();
    ultrasonic.begin();

    Serial.println("AIRena Robot Ready");
}

void loop()
{
    Serial.print("Distance: ");
    Serial.print(ultrasonic.readDistanceCM());
    Serial.println(" cm");

    delay(500);
}