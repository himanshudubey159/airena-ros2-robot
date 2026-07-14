#include "line_follower.h"

LineFollower::LineFollower(MotorController &m, IRSensor &sensor)
    : motor(m), ir(sensor)
{
}

void LineFollower::update()
{
    bool left = ir.left();
    bool center = ir.center();
    bool right = ir.right();

    // Straight
    if (!left && center && !right)
    {
        motor.forward(SPEED);
    }

    // Turn Left
    else if (left && !center)
    {
        motor.turnLeft(SPEED);
    }

    // Turn Right
    else if (right && !center)
    {
        motor.turnRight(SPEED);
    }

    // All sensors detect line (intersection)
    else if (left && center && right)
    {
        motor.stop();
    }

    // Lost line
    else
    {
        motor.stop();
    }
}