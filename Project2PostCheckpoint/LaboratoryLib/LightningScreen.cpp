
/**
 * @file LightningScreen.cpp
 * @author Jacob Stacy
 */

/// Capacity
const double ConnectorCapacity = 1000;

/// Rotation to face left
const double FaceLeft = .75;

/// Background images for the glowing lightningScreen panel
const std::wstring LightningScreenImage = L"/lightning-screen.png";

/// X position for the left sink in pixels
const int SinkX = -100;

/// Y position of both sinks in pixels
const int SinkY = 50;

/// Screen voltage for full illumination
const double ScreenVoltage = 3000;

/// Screen amperage at full voltage
const double ScreenCurrent = 100;

/// Screen Volt to Intensity
const double Volt2Intensity = .001;

/// Spark y
const double SparkY = 100;

/// Spark length
const double SparkLength = 45;


#include "pch.h"

#include <cmath>

#include "LightningScreen.h"

/**
 * Constructor
 * @param name Name
 * @param ImageDir Image Directory
 */
LightningScreen::LightningScreen(const std::wstring& name, const std::wstring& ImageDir)
        : Component(name),
          mSink(this, ImageDir, ConnectorCapacity,wxPoint(0, 0), FaceLeft)
{
    mPolygon.SetImage(ImageDir + LightningScreenImage);
    mPolygon.BottomCenteredRectangle(200);

    mSparky1.SetIntensity(1);
    mSparky2.SetIntensity(1);
    mSparky3.SetIntensity(1);
    mSparky4.SetIntensity(1);
    mSparky5.SetIntensity(1);
    mSparky6.SetIntensity(1);

    mSparky1.SetColour(*wxCYAN);
    mSparky2.SetColour(*wxCYAN);
    mSparky3.SetColour(*wxCYAN);
    mSparky4.SetColour(*wxCYAN);
    mSparky5.SetColour(*wxCYAN);
    mSparky6.SetColour(*wxCYAN);

    std::random_device rd{};
    mSeed = rd();

    mRnd.seed(mSeed);
}

/**
 * Draw
 * @param graphics Graphics
 */
void LightningScreen::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    std::uniform_real_distribution<> dist(0, 1);

    mPolygon.DrawPolygon(graphics, GetPosition().x, GetPosition().y);

    mSink.Draw(graphics, GetPosition().x + SinkX, GetPosition().y - SinkY, FaceLeft);

    double originX = GetPosition().x;
    double originY = GetPosition().y - SparkY;

    double x = originX + SparkLength * sin(dist(mRnd) * M_PI * 2);
    double y = originY - SparkLength * cos(dist(mRnd)* M_PI * 2);

    double x2 = originX + SparkLength * sin(dist(mRnd) * M_PI * 2);
    double y2 = originY - SparkLength * cos(dist(mRnd)* M_PI * 2);

    double x3 = originX + SparkLength * sin(dist(mRnd) * M_PI * 2);
    double y3 = originY - SparkLength * cos(dist(mRnd)* M_PI * 2);

    double x4 = originX + SparkLength * sin(dist(mRnd) * M_PI * 2);
    double y4 = originY - SparkLength * cos(dist(mRnd)* M_PI * 2);

    double x5 = originX + SparkLength * sin(dist(mRnd) * M_PI * 2);
    double y5 = originY - SparkLength * cos(dist(mRnd)* M_PI * 2);

    double x6 = originX + SparkLength * sin(dist(mRnd) * M_PI * 2);
    double y6 = originY - SparkLength * cos(dist(mRnd)* M_PI * 2);

    if (mVoltage >= ScreenVoltage)
    {
        mSparky1.Draw(graphics, GetPosition().x, GetPosition().y - SparkY, x, y);
        mSparky2.Draw(graphics, GetPosition().x, GetPosition().y - SparkY, x2, y2);
        mSparky3.Draw(graphics, GetPosition().x, GetPosition().y - SparkY, x3, y3);
        mSparky4.Draw(graphics, GetPosition().x, GetPosition().y - SparkY, x4, y4);
        mSparky5.Draw(graphics, GetPosition().x, GetPosition().y - SparkY, x5, y5);
        mSparky6.Draw(graphics, GetPosition().x, GetPosition().y - SparkY, x6, y6);
    }
}

/**
 * Sets Position
 * @param x X
 * @param y Y
 */
void LightningScreen::SetPosition(double x, double y)
{
    Component::SetPosition(x, y);

    mSink.SetPosition(GetPosition().x + SinkX, GetPosition().y - SinkY);
}

/**
 * Powers the Sparks
 * @param voltage Volts
 * @return Amps
 */
double LightningScreen::Power(double voltage)
{
    mVoltage = voltage;

    if(voltage < ScreenVoltage)
    {
        return 0;
    }
    return voltage / ScreenVoltage * ScreenCurrent;
}

/**
 * Set time
 * @param time Time
 */
void LightningScreen::SetTime(double time)
{
    Component::SetTime(time);
    mSparky1.SetTime(time);
    mSparky2.SetTime(time);
    mSparky3.SetTime(time);
    mSparky4.SetTime(time);
    mSparky5.SetTime(time);
    mSparky6.SetTime(time);
}

void LightningScreen::Reset(int frame)
{
    mVoltage = 0;
}
