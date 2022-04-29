/**
 * @file PowerSink.cpp
 * @author Jacob Stacy
 */

#include "pch.h"

#include "PowerSink.h"
#include "PowerSource.h"
#include "Component.h"

PowerSink::PowerSink(Component *parent, std::wstring imageDir, double capacity) : mParent(parent)
{

}

double PowerSink::Power(double voltage)
{

    return mParent->Power(voltage);
}

