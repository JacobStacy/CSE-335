/**
 * @file Clamp.cpp
 * @author Jacob Stacy
 */

#include "pch.h"

#include "Clamp.h"

/**
 * Constructor
 * @param x X
 * @param y Y
 * @param speed Speed
 * @param rotation Rotation
 */
Clamp::Clamp(double x, double y, double speed, double rotation)
{
    SetPosition(x, y);

    SetSpeed(speed);

    SetRotation(rotation);
}
