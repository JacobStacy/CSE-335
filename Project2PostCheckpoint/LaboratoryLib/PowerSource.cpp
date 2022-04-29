/**
 * @file PowerSource.cpp
 * @author Jacob Stacy
 */

#include "pch.h"

#include "PowerSource.h"
#include "PowerSink.h"
#include "Component.h"

PowerSource::PowerSource(Component* parent, std::wstring imageDir, double capacity)
{

}

double PowerSource::Power(double voltage)
{
    return mSink->Power(voltage);
}


