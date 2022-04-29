/**
 * @file Switch.cpp
 * @author Jacob Stacy
 */

/// Capacity
const double SwitchCapacity = 200;

#include "pch.h"

#include "Switch.h"

Switch::Switch(const std::wstring& name, const std::wstring& imageDir,
        const std::wstring& onImage, const std::wstring& offImage, int xOffset)
        : Component(name),
        mSink(this, imageDir, SwitchCapacity),
        mOnSource(this, imageDir, SwitchCapacity),
        mOffSource(this, imageDir, SwitchCapacity)
{
    mOn = false;
    mOnPolygon.SetImage(onImage);
    mOffPolygon.SetImage(offImage);

    mOnPolygon.Rectangle(xOffset, 0);
    mOffPolygon.Rectangle(xOffset, 0);
}

void Switch::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    if (mOn)
    {
        mOnPolygon.DrawPolygon(graphics, GetPosition().x, GetPosition().y);
    } else
    {
        mOffPolygon.DrawPolygon(graphics, GetPosition().x, GetPosition().y);
    }
}

void Switch::Update(double elapsed)
{
    Component::Update(elapsed);
}

double Switch::Power(double voltage)
{
    double amps = 0.0;

    if (mOn)
    {
        amps = mOnSource.Power(voltage);
        mOffSource.Power(0);
    } else
    {
        amps = mOffSource.Power(voltage);
        mOnSource.Power(0);
    }

    return amps;
}

void Switch::XmlLoad(wxXmlNode* node)
{
    if(node->GetAttribute(L"on") == L"true")
    {
        mOn = true;
    } else
    {
        mOn = false;
    }

}

void Switch::Reset(int frame)
{
    mOn = false;
}


