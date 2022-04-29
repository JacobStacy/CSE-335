/**
 * @file MotionSource.cpp
 * @author Jacob Stacy
 */

#include "pch.h"

#include "MotionSource.h"
#include "MotionSink.h"

double MotionSource::Move(double time, double duration, double position)
{
    mSink->Move(position);
    return 0;
}
