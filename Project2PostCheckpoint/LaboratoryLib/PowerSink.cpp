/**
 * @file PowerSink.cpp
 * @author Jacob Stacy
 */

#include "pch.h"

#include "PowerSink.h"
#include "PowerSource.h"
#include "Component.h"
#include "Polygon.h"

/// Image to use for power connections
const std::wstring ConnectionImage = L"/fitting.png";

/// Smallest size to display the connection
const int ConnectionMinimumSize = 10;

/// Used to compute the size of the connection image.
const int ConnectionCapacityDivisor = 100;

double PowerSink::Power(double voltage)
{
    return mParent->Power(voltage);
}

void PowerSink::Draw(std::shared_ptr<wxGraphicsContext> graphics, double x, double y, double rotation)
{
    cse335::Polygon polygon = cse335::Polygon();

    int size = ConnectionMinimumSize + mCapacity / ConnectionCapacityDivisor;

    polygon.SetImage(mImageDir + ConnectionImage);
    polygon.Rectangle(-size/2, 0, size, size);
    polygon.SetRotation(rotation);

    polygon.DrawPolygon(graphics, x, y);

//    auto vector = cse335::GraphicsHelper::ToIntVector(rotation, size);
}

