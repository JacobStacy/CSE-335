/**
 * @file MotionSink.cpp
 * @author Jacob Stacy
 */

#include "pch.h"

#include "MotionSink.h"

void MotionSink::Move(double position)
{
    mParent->Update(position);
}
