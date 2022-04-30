/**
 * @file Rheostat.cpp
 * @author Jacob Stacy
 */

/// Capacity
const double ConnectorCapacity = 100;

/// Rotation to face right
const double FaceRight = .25;

/// Rotation to face left
const double FaceLeft = .75;

/// Back Image
const std::wstring BackImage = L"/rheostat.png";

/// Wheel Image
const std::wstring WheelImage = L"/rheostat-knob.png";

/// Connector X
const double ConnectorX = 25;

/// Connector X
const double ConnectorY = 25;

/// Wheel Y
const double WheelY = 25;



#include "pch.h"

#include "Rheostat.h"

/**
 * Constructor
 * @param name Name
 * @param ImageDir Image Directory
 */
Rheostat::Rheostat(const std::wstring& name, const std::wstring& ImageDir)
        : Component(name),
        mSink(this, ImageDir, ConnectorCapacity, wxPoint(0,0), FaceLeft)
{
    mSource = std::make_shared<PowerSource>(this, ImageDir, ConnectorCapacity,wxPoint(0, 0), FaceRight);

    mBackPolygon.SetImage(ImageDir + BackImage);
    mWheelPolygon.SetImage(ImageDir + WheelImage);

    mBackPolygon.BottomCenteredRectangle(50);
    mWheelPolygon.CenteredSquare(50);
}

/**
 * Draws
 * @param graphics Graphics
 */
void Rheostat::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    mBackPolygon.DrawPolygon(graphics, GetPosition().x, GetPosition().y);
    mWheelPolygon.DrawPolygon(graphics, GetPosition().x, GetPosition().y - WheelY);

    mSource->Draw(graphics, GetPosition().x + ConnectorX, GetPosition().y - ConnectorY, FaceRight);
    mSink.Draw(graphics, GetPosition().x - ConnectorX, GetPosition().y - ConnectorY, FaceLeft);
}

/**
 * Set Time
 * @param time Time
 */
void Rheostat::SetTime(double time)
{
    if(mDuration > 0)
    {
        double speed = (mRotation - mWheelPolygon.GetRotation()) / mDuration;

        double addedRotation = (speed * (time - mPrevTime));

        mWheelPolygon.SetRotation(mWheelPolygon.GetRotation() + addedRotation);

        mResistance = mWheelPolygon.GetRotation() * 2;

        mDuration -= (time - mPrevTime);

        mPrevTime = time;

    } else
    {
        mPrevTime = time;
    }
}

/**
 * Load
 * @param node node
 */
void Rheostat::XmlLoad(wxXmlNode* node)
{
    mRotation = wxAtof(node->GetAttribute(L"rotate-to"));
    mDuration = wxAtof(node->GetAttribute(L"duration"));

    mPrevTime = 2;
}

/**
 * Reset
 * @param frame
 */
void Rheostat::Reset(int frame)
{
    mWheelPolygon.SetRotation(0);
    mDuration = 0;
    mRotation = 0;
}

/**
 * Set pOs
 * @param x X
 * @param y Y
 */
void Rheostat::SetPosition(double x, double y)
{
    Component::SetPosition(x, y);

    mSource->SetPosition(GetPosition().x + ConnectorX, GetPosition().y - ConnectorY);

    mSink.SetPosition(GetPosition().x - ConnectorX, GetPosition().y - ConnectorY);
}

/**
 * Power
 * @param voltage Voltage
 * @return amps
 */
double Rheostat::Power(double voltage)
{
    return mSource->Power(voltage * mResistance);
}
