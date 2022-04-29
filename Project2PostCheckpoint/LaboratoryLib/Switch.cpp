/**
 * @file Switch.cpp
 * @author Jacob Stacy
 */

#include "pch.h"

#include "Switch.h"

/// Capacity
const double SwitchCapacity = 200;

/// The image to use for the switch on
const std::wstring SwitchOnImage = L"/knifeswitch-on.png";

/// The image to use for the switch on
const std::wstring SwitchOffImage = L"/knifeswitch-off.png";

/// X location for connections for the left side of the switch
const int SwitchLeftX = -22;

/// X location for connections for the right side of the switch
const int SwitchRightX = 22;

/// Y location for sink
const int SwitchSinkY = -63;

/// Y position for the switch down source
const int SwitchSource0Y = -37;

/// Y position for the switch up source
const int SwitchSource1Y = -89;

/// Rotation to face right
const double FaceRight = .25;

/// Rotation to face left
const double FaceLeft = .75;

/**
 * Constructor
 * @param name Name
 * @param imageDir ImageDir
 * @param side Side that the connections are on | True = Left, False = Right
 */
Switch::Switch(const std::wstring& name, const std::wstring& imageDir, bool side)
        : Component(name),
        mSink(this, imageDir, SwitchCapacity),
        mOnSource(this, imageDir, SwitchCapacity),
        mOffSource(this, imageDir, SwitchCapacity),
        mSide(side)
{
    mOn = false;
    mOnPolygon.SetImage(imageDir + SwitchOnImage);
    mOffPolygon.SetImage(imageDir + SwitchOffImage);

    mOnPolygon.BottomCenteredRectangle();
    mOffPolygon.BottomCenteredRectangle();
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

    if (mSide)
    {
        mOnSource.Draw(graphics, GetPosition().x + SwitchLeftX, GetPosition().y + SwitchSource0Y, FaceLeft);
        mOffSource.Draw(graphics, GetPosition().x + SwitchLeftX, GetPosition().y + SwitchSource1Y, FaceLeft);
        mSink.Draw(graphics, GetPosition().x + SwitchLeftX, GetPosition().y + SwitchSinkY, FaceLeft);
    } else
    {
        mOnSource.Draw(graphics, GetPosition().x + SwitchRightX, GetPosition().y + SwitchSource0Y, FaceRight);
        mOffSource.Draw(graphics, GetPosition().x + SwitchRightX, GetPosition().y + SwitchSource1Y, FaceRight);
        mSink.Draw(graphics, GetPosition().x + SwitchRightX, GetPosition().y + SwitchSinkY, FaceRight);
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


