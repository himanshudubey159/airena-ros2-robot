#pragma once

// ======================================================
// AIRena Robot Pin Definitions
// ======================================================

// -------- L298N Motor Driver --------
constexpr uint8_t MOTOR_LEFT_EN  = 25;
constexpr uint8_t MOTOR_LEFT_IN1 = 26;
constexpr uint8_t MOTOR_LEFT_IN2 = 27;

constexpr uint8_t MOTOR_RIGHT_EN  = 14;
constexpr uint8_t MOTOR_RIGHT_IN1 = 12;
constexpr uint8_t MOTOR_RIGHT_IN2 = 13;

// -------- IR Sensors --------
constexpr uint8_t IR_LEFT   = 34;
constexpr uint8_t IR_CENTER = 35;
constexpr uint8_t IR_RIGHT  = 32;

// -------- Ultrasonic --------
constexpr uint8_t US_TRIG = 5;
constexpr uint8_t US_ECHO = 18;

// -------- Servo --------
constexpr uint8_t SERVO_PIN = 19;