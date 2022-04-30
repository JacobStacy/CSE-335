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

/**
 * Constructor
 * @param parent Parent
 * @param imageDir Image Directory
 * @param capacity Capacity
 * @param point start position
 * @param rotation start rotation
 * @param speed start speed
 */
PowerSink::PowerSink(Component* parent, const std::wstring& imageDir, double capacity, wxPoint point, double rotation, double speed)
        : mParent(parent), mImageDir(imageDir), mCapacity(capacity)
{
    SetRotation(rotation);
    SetSpeed(speed);
}

/**
 * Powers the component
 * @param voltage Voltage Supplied
 * @return Current Drawn
 */
double PowerSink::Power(double voltage)
{
    mVoltage = voltage;
    return mParent->Power(voltage);
}

/**
 * Draws the Sink
 * @param graphics Graphics
 * @param x X position
 * @param y Y position
 * @param rotation Rotation
 */
void PowerSink::Draw(std::shared_ptr<wxGraphicsContext> graphics, double x, double y, double rotation)
{
    cse335::Polygon polygon = cse335::Polygon();

    SetPosition(x,y);

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
wxPoint PowerSink::GetPosition()
{
    double originX = BezierEnd::GetPosition().x;
    double originY = BezierEnd::GetPosition().y;

    int size = ConnectionMinimumSize + mCapacity / ConnectionCapacityDivisor;

    double x = originX + size * sin(GetRotation()* M_PI * 2);
    double y = originY - size * cos(GetRotation()* M_PI * 2);

    return wxPoint(x, y);
}

