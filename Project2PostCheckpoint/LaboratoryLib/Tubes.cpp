
/**
 * @file Tubes.cpp
 * @author Jacob Stacy
 */

/// Capacity
const double ConnectorCapacity = 200;

/// Rotation to face right
const double FaceDown = .5;

/// Background images for the glowing tubes panel
const std::wstring GlowingTubesBackgroundImage = L"/tubes.png";

/// Image for the left glowing tube
const std::wstring GlowingTubesLeftImage = L"/tubes-left-glow.png";

/// Image for the right glowing tube
const std::wstring GlowingTubesRightImage = L"/tubes-right-glow.png";

/// X position for the left sink in pixels
const int SinkLeftX = 16;

/// X position for the right sink in pixels
const int SinkRightX = -16;

/// Y position of both sinks in pixels
const int SinkY = 3;

/// Light voltage for full illumination
const double LightVoltage = 1000;

/// Light amperage at full voltage
const double LightCurrent = 100;

/// Light Volt to Intensity
const double Volt2Intensity = .001;


#include "pch.h"

#include "Tubes.h"

/**
 * Constructor
 * @param name Name
 * @param ImageDir Image Directory
 */
Tubes::Tubes(const std::wstring& name, const std::wstring& ImageDir)
        : Component(name),
          mSinkLeft(this, ImageDir, ConnectorCapacity,wxPoint(0, 0), FaceDown),
          mSinkRight(this, ImageDir, ConnectorCapacity, wxPoint(0,0), FaceDown)
{
    mBackPolygon.SetImage(ImageDir + GlowingTubesBackgroundImage);
    mLeftPolygon.SetImage(ImageDir + GlowingTubesLeftImage);
    mRightPolygon.SetImage(ImageDir + GlowingTubesRightImage);

    mLeftPolygon.SetOpacity(0);
    mRightPolygon.SetOpacity(0);

    mBackPolygon.BottomCenteredRectangle();
    mLeftPolygon.BottomCenteredRectangle();
    mRightPolygon.BottomCenteredRectangle();
}

/**
 * Draws
 * @param graphics Graphics
 */
void Tubes::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    mBackPolygon.DrawPolygon(graphics, GetPosition().x, GetPosition().y);

    mLeftPolygon.SetOpacity(mLeftVoltage * Volt2Intensity);
    mRightPolygon.SetOpacity(mRightVoltage * Volt2Intensity);

    mLeftPolygon.DrawPolygon(graphics, GetPosition().x, GetPosition().y);
    mRightPolygon.DrawPolygon(graphics, GetPosition().x, GetPosition().y);

    mSinkLeft.Draw(graphics, GetPosition().x + SinkLeftX, GetPosition().y - SinkY, FaceDown);
    mSinkLeft.Draw(graphics, GetPosition().x + SinkRightX, GetPosition().y - SinkY, FaceDown);
}

/**
 * Sets Position
 * @param x X
 * @param y Y
 */
void Tubes::SetPosition(double x, double y)
{
    Component::SetPosition(x, y);

    mSinkLeft.SetPosition(GetPosition().x + SinkLeftX, GetPosition().y - SinkY);
    mSinkRight.SetPosition(GetPosition().x + SinkRightX, GetPosition().y - SinkY);
}

/**
 * Powers
 * @param voltage Voltage
 * @return amps
 */
double Tubes::Power(double voltage)
{
    mLeftVoltage = mSinkLeft.GetVoltage();
    mRightVoltage = mSinkRight.GetVoltage();

    double current = mLeftVoltage / LightVoltage * LightCurrent;
    current += mRightVoltage / LightVoltage * LightCurrent;
    return current;
}

/**
 * Resets
 * @param frame frame
 */
void Tubes::Reset(int frame)
{
    mLeftVoltage = 0;
    mRightVoltage = 0;
}
