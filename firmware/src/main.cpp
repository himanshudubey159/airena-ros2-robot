#include <Arduino.h>

#include "motor.h"
#include "ir_sensor.h"
#include "ultrasonic.h"
#include "servo_control.h"
#include "line_follower.h"

MotorController motor;
IRSensor ir;
Ultrasonic ultrasonic;
ServoControl servo;

LineFollower lineFollower(motor, ir);

void setup()
{
    Serial.begin(115200);

    motor.begin();
    ir.begin();
    ultrasonic.begin();
    servo.begin();

    Serial.println();
    Serial.println("===============================");
    Serial.println("   AIRena Robot Started");
    Serial.println("===============================");
}

void loop()
{
    // Basic line following
    lineFollower.update();

    // Print ultrasonic distance every 500 ms
    static unsigned long lastPrint = 0;

    if (millis() - lastPrint >= 500)
    {
        lastPrint = millis();

        Serial.print("Distance: ");
        Serial.print(ultrasonic.readDistanceCM());
        Serial.println(" cm");
    }

    delay(10);
}