/**
 * @file MotionSource.cpp
 * @author Jacob Stacy
 */

#include "pch.h"

#include "MotionSource.h"
#include "MotionSink.h"

/**
 * Handle Movement
 * @param time Time
 * @param duration Duration
 * @param position Position
 * @return 0
 */
double MotionSource::Move(double time, double duration, double position)
{
    mSink->Move(position);
    return 0;
}
