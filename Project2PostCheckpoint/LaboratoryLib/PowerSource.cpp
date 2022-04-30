/**
 * @file PowerSource.cpp
 * @author Jacob Stacy
 */

#include "pch.h"

#include "PowerSource.h"
#include "PowerSink.h"
#include "Component.h"
#include "Polygon.h"

/// Image to use for power connections
const std::wstring ConnectionImage = L"/fitting.png";

/// Smallest size to display the connection
const int ConnectionMinimumSize = 10;

/// Used to compute the size of the connection image.
const int ConnectionCapacityDivisor = 100;


/**
 * Constructor
 * @param parent Parent
 * @param imageDir Dir
 * @param capacity Capacity
 * @param point Point
 * @param rotation Rotation
 * @param speed Speed
 */
PowerSource::PowerSource(Component* parent, std::wstring imageDir, double capacity, wxPoint point, double rotation, double speed)
        : mImageDir(imageDir), mCapacity(capacity)
{
    SetRotation(rotation);
    SetSpeed(speed);
}

/**
 * Powers
 * @param voltage Volts
 * @return Amps
 */
double PowerSource::Power(double voltage)
{
    if (mSink != nullptr)
    {
        return mSink->Power(voltage);
    } else
    {
        return 0;
    }
}

/**
 * Draws PowerSource
 * @param graphics Graphics
 * @param x X
 * @param y Y
 * @param rotation Rotation
 */
void PowerSource::Draw(std::shared_ptr<wxGraphicsContext> graphics, double x, double y, double rotation)
{
    cse335::Polygon polygon = cse335::Polygon();

    int size = ConnectionMinimumSize + mCapacity / ConnectionCapacityDivisor;

    polygon.SetImage(mImageDir + ConnectionImage);
    polygon.Rectangle(-size/2, 0, size, size);
    polygon.SetRotation(GetRotation());

    SetPosition(x, y);

    polygon.DrawPolygon(graphics, x, y);

//    auto vector = cse335::GraphicsHelper::ToIntVector(rotation, size);
}

/**
 * Get Pos
 * @return pos
 */
wxPoint PowerSource::GetPosition()
{
    double originX = BezierEnd::GetPosition().x;
    double originY = BezierEnd::GetPosition().y;

    int size = ConnectionMinimumSize + mCapacity / ConnectionCapacityDivisor;

    double x = originX + size * sin(GetRotation()* M_PI * 2);
    double y = originY - size * cos(GetRotation()* M_PI * 2);

    return wxPoint(x, y);
}


