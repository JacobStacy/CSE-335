/**
 * @file Light.cpp
 * @author Jacob Stacy
 */

/// Light voltage for full illumination
const double LightVoltage = 1000;

/// Light amperage at full voltage
const double LightCurrent = 100;

#include "pch.h"

#include "Light.h"

/**
 * Constructor
 * @param name Name
 * @param onImage Image while On
 * @param offImage Image While Off
 */
Light::Light(const std::wstring& name, const std::wstring& imageDir, const std::wstring& onImage, const std::wstring& offImage, int xOffset)
        : Component(name), mSink(this, imageDir, LightCurrent)
{
    mOn = false;

    //162

    mOnPolygon.SetImage(onImage);
    mOffPolygon.SetImage(offImage);

    mOnPolygon.Rectangle(xOffset/2, 0);
    mOffPolygon.Rectangle(xOffset/2, 0);

}

void Light::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    mOffPolygon.DrawPolygon(graphics, GetPosition().x, GetPosition().y);

    if(mOn){
        mOnPolygon.DrawPolygon(graphics, GetPosition().x, GetPosition().y);
    }
}

void Light::Update(double elapsed)
{
    Component::Update(elapsed);
}

double Light::Power(double voltage)
{
    mOn = false;

    if (voltage > 0)
    {
        mOn = true;
    }

    return voltage / LightVoltage * LightCurrent;
}

