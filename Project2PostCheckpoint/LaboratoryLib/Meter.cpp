
/**
 * @file Meter.cpp
 * @author Jacob Stacy
 */

/// Capacity
const double ConnectorCapacity = 200;

/// Rotation to face right
const double FaceRight = .25;

/// Rotation to face left
const double FaceLeft = .75;

/// Back Image
const std::wstring Image = L"/meters-5u.png";

/// Connector X
const double ConnectorX = 57;

/// Connector X
const double ConnectorY = 26;

/// Line X
const double LineX = 24;

/// Line Y
const double LineY = 14;

/// Line Length
const double LineLength = 26;

/// Start Length
const double LineStartLength = 13;

/// Zero Angle
const double ZeroAngle = 135;

/// Conversion Rate
const double AngleRatio = 0.09;




#include "pch.h"

#include "Meter.h"

/**
 * Constructor
 * @param name Name
 * @param ImageDir Image Dir
 */
Meter::Meter(const std::wstring& name, const std::wstring& ImageDir)
        : Component(name),
          mSink(this, ImageDir, ConnectorCapacity, wxPoint(0,0), FaceLeft)
{
    mSource = std::make_shared<PowerSource>(this, ImageDir, ConnectorCapacity,wxPoint(0, 0), FaceRight);

    mPolygon.SetImage(ImageDir + Image);

    mPolygon.BottomCenteredRectangle();
}

/**
 * Draws
 * @param graphics Graphics
 */
void Meter::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    mPolygon.DrawPolygon(graphics, GetPosition().x, GetPosition().y);

    mSource->Draw(graphics, GetPosition().x + ConnectorX, GetPosition().y - ConnectorY, FaceRight);
    mSink.Draw(graphics, GetPosition().x - ConnectorX, GetPosition().y - ConnectorY, FaceLeft);

    wxPen pen = wxPen(*wxRED);
    pen.SetWidth(1);
    pen.SetCap(wxCAP_BUTT);
    graphics->SetPen(pen);

    //
    // Volt Side
    //
    double originXV = GetPosition().x - LineX;
    double originYV = GetPosition().y - LineY;

    double angleV = (ZeroAngle - (mVoltage * AngleRatio)) / (180 / M_PI);

    double startXV = originXV + LineStartLength * cos(angleV);
    double startYV = originYV - LineStartLength * sin(angleV);

    double endXV = originXV + LineLength * cos(angleV);
    double endYV = originYV - LineLength * sin(angleV);

    graphics->StrokeLine(startXV, startYV, endXV, endYV);

    //
    // Amp Side
    //
    double originXA = GetPosition().x + LineX;
    double originYA = GetPosition().y - LineY;

    double angleA = (ZeroAngle - (mCurrent * AngleRatio)) / (180 / M_PI);

    double startXA = originXA + LineStartLength * cos(angleA);
    double startYA = originYA - LineStartLength * sin(angleA);

    double endXA = originXA + LineLength * cos(angleA);
    double endYA = originYA - LineLength * sin(angleA);

    graphics->StrokeLine(startXA, startYA, endXA, endYA);
}

/**
 * Set Pos
 * @param x X
 * @param y Y
 */
void Meter::SetPosition(double x, double y)
{
    Component::SetPosition(x, y);

    mSource->SetPosition(GetPosition().x + ConnectorX, GetPosition().y - ConnectorY);

    mSink.SetPosition(GetPosition().x - ConnectorX, GetPosition().y - ConnectorY);
}

/**
 * Power
 * @param voltage volt
 * @return amps
 */
double Meter::Power(double voltage)
{
    mVoltage = voltage;
    mCurrent = mSource->Power(voltage);

    return mCurrent;
}