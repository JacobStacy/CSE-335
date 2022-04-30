/**
 * @file Orbs.cpp
 * @author Jacob Stacy
 */

#include "pch.h"

#include "Orbs.h"
#include "Sparky.h"

/// Orb voltage for full power
const double OrbsVoltage = 1000;

/// Voltage below which the orbs do not spark.
const double OrbsMinVoltage = 250;

/// Orb amperage at full voltage
const double OrbsCurrent = 200;

/// Position on the Orbs where the power is connected
const wxPoint OrbsSinkPosition = wxPoint(-132, -110);

/// X offset to the left orb spark end in pixels
const int SparkOffset1X = -72;

/// X offset to the right orb spark end in pixels
const int SparkOffset2X = 75;

/// Y offset for the orb spark ends
const int SparkOffsetY = -45;

/// The factor by which you convert the rotation number to position
const double RotationPositionRatio = 250;

/// Rotation to face left
const double FaceLeft = .75;

/**
 * Constuctor
 * @param name Name
 * @param imageDir Image Dir
 * @param image Image for Orb
 */
Orbs::Orbs(const std::wstring& name, const std::wstring& imageDir, const std::wstring& image)
        : Component(name), mMotionSink(this), mPowerSink(this, imageDir, OrbsCurrent, wxPoint(0,0), FaceLeft)
{
    mPolygon.SetImage(image);
    mPolygon.BottomCenteredRectangle();

    mPowerSink.SetPosition(GetPosition().x + OrbsSinkPosition.x, GetPosition().y + OrbsSinkPosition.y + mMovement);

    mSparky.SetIntensity(1);
}

/**
 * Draws Orb
 * @param graphics Graphics
 */
void Orbs::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    mPolygon.DrawPolygon(graphics, GetPosition().x, GetPosition().y + mMovement);

    mPowerSink.Draw(graphics, GetPosition().x + OrbsSinkPosition.x, GetPosition().y + OrbsSinkPosition.y + mMovement, FaceLeft);

    if (mVoltage > OrbsMinVoltage)
    {
    mSparky.Draw(graphics,
            GetPosition().x + SparkOffset1X, GetPosition().y + mMovement + SparkOffsetY,
            GetPosition().x + SparkOffset2X, GetPosition().y + mMovement + SparkOffsetY);
    }

    mPowerSink.SetPosition(GetPosition().x + OrbsSinkPosition.x, GetPosition().y + OrbsSinkPosition.y + mMovement);


}

/**
 * Sets time
 * @param time Time
 */
void Orbs::SetTime(double time)
{
    mSparky.SetTime(time);
}

/**
 * Resets
 * @param frame Frame
 */
void Orbs::Reset(int frame)
{
    mSparky.Reset();
}

/**
 * Updates Movement
 * @param position Position
 */
void Orbs::Update(double position)
{
    mMovement = position * RotationPositionRatio;
}

/**
 * Powers orb
 * @param voltage Votage
 * @return Amps
 */
double Orbs::Power(double voltage)
{
    mVoltage = voltage;
    if (voltage < OrbsMinVoltage)
    {
        return 0;
    }

    return voltage / OrbsVoltage * OrbsCurrent;
}

/**
 * Sets Position
 * @param x X
 * @param y Y
 */
void Orbs::SetPosition(double x, double y)
{
    Component::SetPosition(x, y);
    mPowerSink.SetPosition(GetPosition().x + OrbsSinkPosition.x, GetPosition().y + OrbsSinkPosition.y + mMovement);
    mPowerSink.SetRotation(FaceLeft);
}




