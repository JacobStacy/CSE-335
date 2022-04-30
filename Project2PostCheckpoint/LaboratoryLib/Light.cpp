/**
 * @file Light.cpp
 * @author Jacob Stacy
 */

/// Light voltage for full illumination
const double LightVoltage = 1000;

/// Light amperage at full voltage
const double LightCurrent = 100;

/// Rotation for Sink
const double SinkRotation = .8;

/// XOffset for sink
const double SinkX = 15;

/// YOffset for sink
const double SinkY = -120;

#include "pch.h"

#include "Light.h"

/**
 * Constructor
 * @param name Name
 * @param imageDir Dir
 * @param onImage Image while On
 * @param offImage Image While Off
 * @param xOffset Offset
 */
Light::Light(const std::wstring& name, const std::wstring& imageDir, const std::wstring& onImage, const std::wstring& offImage, int xOffset)
        : Component(name), mSink(this, imageDir, LightCurrent * 7, wxPoint(0,0), SinkRotation)
{
    mOn = false;

    //162

    mOnPolygon.SetImage(onImage);
    mOffPolygon.SetImage(offImage);

    mOnPolygon.Rectangle(xOffset/2, 0);
    mOffPolygon.Rectangle(xOffset/2, 0);

    mSink.SetPosition(GetPosition().x + SinkX, GetPosition().y + SinkY);

}

/**
 * Draws the light
 * @param graphics Graphics
 */
void Light::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    mOffPolygon.DrawPolygon(graphics, GetPosition().x, GetPosition().y);

    if(mOn){
        mOnPolygon.DrawPolygon(graphics, GetPosition().x, GetPosition().y);
    }

    mSink.Draw(graphics, GetPosition().x + SinkX, GetPosition().y + SinkY, SinkRotation);
}


/**
 * Power Light
 * @param voltage voltage
 * @return amps
 */
double Light::Power(double voltage)
{
    mOn = false;

    if (voltage > 0)
    {
        mOn = true;
    }

    return voltage / LightVoltage * LightCurrent;
}

