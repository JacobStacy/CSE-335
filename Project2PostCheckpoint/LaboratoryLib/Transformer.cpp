
/**
 * @file Transformer.cpp
 * @author Jacob Stacy
 */

/// Capacity
const double ConnectorCapacity = 1000;

/// Rotation to face up
const double FaceUp = 0;

/// Background images for the glowing transformer panel
const std::wstring TransformerImage = L"/transformer.png";

/// X position for the left sink in pixels
const int SinkX = -68;

/// Y position of both sinks in pixels
const int SinkY = 276;

/// X position for the left sink in pixels
const int SourceX = 66;

/// Y position of both sinks in pixels
const int SourceY = 276;

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

#include "Transformer.h"

/**
 * Constructor
 * @param name Name
 * @param imageDir Image Directory
 * @param step How much to step up
 */
Transformer::Transformer(const std::wstring& name, const std::wstring& imageDir, double step)
        : Component(name),
            mStep(step),
            mSink(this, imageDir, ConnectorCapacity,wxPoint(0, 0), FaceUp)
{
    mSource = std::make_shared<PowerSource>(this, imageDir, ConnectorCapacity, wxPoint(0, 0), FaceUp);
    mPolygon.SetImage(imageDir + TransformerImage);
    mPolygon.BottomCenteredRectangle(200);

}

/**
 * Draw
 * @param graphics Graphics
 */
void Transformer::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    std::uniform_real_distribution<> dist(0, 1);

    mPolygon.DrawPolygon(graphics, GetPosition().x, GetPosition().y);

    mSink.Draw(graphics, GetPosition().x + SinkX, GetPosition().y - SinkY, FaceUp);

    mSource->Draw(graphics, GetPosition().x + SourceX, GetPosition().y - SourceY, FaceUp);
}

/**
 * Sets Position
 * @param x X
 * @param y Y
 */
void Transformer::SetPosition(double x, double y)
{
    Component::SetPosition(x, y);

    mSink.SetPosition(GetPosition().x + SinkX, GetPosition().y - SinkY);
    mSource->SetPosition(GetPosition().x + SourceX, GetPosition().y - SourceY);
}

/**
 * Powers the Sparks
 * @param voltage Volts
 * @return Amps
 */
double Transformer::Power(double voltage)
{
    return mSource->Power(voltage * mStep);
}

/**
 * Set time
 * @param time Time
 */
void Transformer::SetTime(double time)
{
    Component::SetTime(time);
}
