/**
 * @file DistributionPanel.cpp
 * @author Jacob Stacy
 */
#include "pch.h"

#include "DistributionPanel.h"
#include "PowerSource.h"

/**
 * Constructor
 * @param name
 * @param imageDir
 */
DistributionPanel::DistributionPanel(const std::wstring& name, const std::wstring& image, const std::wstring& imageDir) : Component(name), mSink (this, imageDir, 100)
{
    mPolygon.SetImage(image);
    mPolygon.BottomCenteredRectangle();
}

/**
 * Supply voltage to this component.
 * @param voltage Voltage supplied in volts
 * @return Amperage consumed by the component.
 */
double DistributionPanel::Power(double voltage)
{
    double amperage = 0;
    for(auto &source : mSources)
    {
        amperage += source.Power(voltage);
    }

    return amperage;
}

void DistributionPanel::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    mPolygon.DrawPolygon(graphics, GetPosition().x, GetPosition().y);
}

void DistributionPanel::Update(double elapsed)
{
    Component::Update(elapsed);
}
