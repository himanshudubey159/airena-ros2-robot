#include <Arduino.h>
#include "motor.h"
#include "pins.h"

constexpr uint8_t LEFT_PWM_CHANNEL  = 0;
constexpr uint8_t RIGHT_PWM_CHANNEL = 1;

constexpr uint32_t PWM_FREQUENCY = 5000;
constexpr uint8_t PWM_RESOLUTION = 8;


void MotorController::begin()
{
    pinMode(MOTOR_LEFT_IN1, OUTPUT);
    pinMode(MOTOR_LEFT_IN2, OUTPUT);

    pinMode(MOTOR_RIGHT_IN1, OUTPUT);
    pinMode(MOTOR_RIGHT_IN2, OUTPUT);

    // Configure PWM
    ledcSetup(0, PWM_FREQUENCY, PWM_RESOLUTION);
    ledcAttachPin(MOTOR_LEFT_EN, 0);

    ledcSetup(1, PWM_FREQUENCY, PWM_RESOLUTION);
    ledcAttachPin(MOTOR_RIGHT_EN, 1);

    stop();
}


void MotorController::setLeftMotor(int speed)
{
    speed = constrain(speed, -255, 255);

    if (speed >= 0)
    {
        digitalWrite(MOTOR_LEFT_IN1, HIGH);
        digitalWrite(MOTOR_LEFT_IN2, LOW);
        ledcWrite(0, speed);
    }
    else
    {
        digitalWrite(MOTOR_LEFT_IN1, LOW);
        digitalWrite(MOTOR_LEFT_IN2, HIGH);
        ledcWrite(0, speed);
    }
}

void MotorController::setRightMotor(int speed)
{
    speed = constrain(speed, -255, 255);

    if (speed >= 0)
    {
        digitalWrite(MOTOR_RIGHT_IN1, HIGH);
        digitalWrite(MOTOR_RIGHT_IN2, LOW);
        ledcWrite(1, speed);
    }
    else
    {
        digitalWrite(MOTOR_RIGHT_IN1, LOW);
        digitalWrite(MOTOR_RIGHT_IN2, HIGH);
        ledcWrite(1, speed);
    }
}

void MotorController::forward(uint8_t speed)
{
    setLeftMotor(speed);
    setRightMotor(speed);
}

void MotorController::backward(uint8_t speed)
{
    setLeftMotor(-speed);
    setRightMotor(-speed);
}

void MotorController::turnLeft(uint8_t speed)
{
    setLeftMotor(-speed);
    setRightMotor(speed);
}

void MotorController::turnRight(uint8_t speed)
{
    setLeftMotor(speed);
    setRightMotor(-speed);
}
void MotorController::stop()
{
    digitalWrite(MOTOR_LEFT_IN1, LOW);
    digitalWrite(MOTOR_LEFT_IN2, LOW);

    digitalWrite(MOTOR_RIGHT_IN1, LOW);
    digitalWrite(MOTOR_RIGHT_IN2, LOW);

    ledcWrite(0, 0);
    ledcWrite(1, 0);
}