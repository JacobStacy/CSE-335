/**
 * @file MotionSink.cpp
 * @author Jacob Stacy
 */

#include "pch.h"

#include "MotionSink.h"

/**
 * Handles Movement
 * @param position Positon
 */
void MotionSink::Move(double position)
{
    mParent->Update(position);
}
