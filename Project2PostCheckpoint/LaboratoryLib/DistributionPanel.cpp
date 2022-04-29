/**
 * @file DistributionPanel.cpp
 * @author Jacob Stacy
 */
#include "pch.h"

#include "DistributionPanel.h"
#include "PowerSource.h"

/// The image to use for the distribution panel
const std::wstring DistributionImage = L"/dist-6u.png";

/// Y location for the sources in pixels
const int SourcesY = -35;

/// X location for the first source in pixels
const int SourcesX = -35;

/// Spacing between the sources in pixels
const int SourcesSpacing = 15;

/// Location of the sink on the
const wxPoint DistributionSinkPosition = wxPoint(-48, -20);

/// Rotation to face up
const double FaceUp = 0;

/// Rotation to face left
const double FaceLeft = .75;

/**
 * Constructor
 * @param name
 * @param imageDir
 */
DistributionPanel::DistributionPanel(const std::wstring& name, const std::wstring& imageDir) : Component(name), mSink (this, imageDir, 1000)
{
    mPolygon.SetImage(imageDir + DistributionImage);
    mPolygon.BottomCenteredRectangle();
}

void DistributionPanel::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    mPolygon.DrawPolygon(graphics, GetPosition().x, GetPosition().y);

    mSink.Draw(graphics, GetPosition().x + DistributionSinkPosition.x, GetPosition().y + DistributionSinkPosition.y, FaceLeft);

    int currentSourceX = SourcesX;
    for (auto source : mSources)
    {
        source->Draw(graphics, GetPosition().x + currentSourceX, GetPosition().y + SourcesY, FaceUp);

        currentSourceX += SourcesSpacing;
    }
}

/**
 * Supply voltage to this component.
 * @param voltage Voltage supplied in volts
 * @return Amperage consumed by the component.
 */
double DistributionPanel::Power(double voltage)
{
    double amperage = 0;
    for(auto source : mSources)
    {
        amperage += source->Power(voltage);
    }

    return amperage;
}

void DistributionPanel::Update(double elapsed)
{
    Component::Update(elapsed);
}

void DistributionPanel::AddSource(const std::wstring imageDir, double capacity)
{
    mSources.push_back(std::make_shared<PowerSource>(this, imageDir, capacity));
}
