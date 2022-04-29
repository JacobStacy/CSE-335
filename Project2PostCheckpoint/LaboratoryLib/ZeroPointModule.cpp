/**
 * @file ZeroPointModule.cpp
 * @author Jacob Stacy
 */

#include "pch.h"

#include <sstream>

#include "ZeroPointModule.h"

/// Offset of the text
const double TextOffset = 80;

/// The ZPM output voltage
const double ZPMVoltage = 1000;

/**
 * Constructor
 * @param name Name
 */
ZeroPointModule::ZeroPointModule(const std::wstring& name, const std::wstring& imageDir) : Component(name), mSource(this, imageDir, ZPMVoltage)
{
    mAmps = 0;
}

void ZeroPointModule::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    mPolygon.DrawPolygon(graphics, GetPosition().x, GetPosition().y); // Replace with visual shape

    wxFont font(wxSize(0, 25),
            wxFONTFAMILY_SWISS,
            wxFONTSTYLE_NORMAL,
            wxFONTWEIGHT_NORMAL);

    graphics->SetFont(font, *wxWHITE);

    // Get Width of the String
    double numWidth, h;

    std::ostringstream ossV;
    ossV << mVoltage * 1000;
    graphics->GetTextExtent(ossV.str(), &numWidth, &h);
    graphics->DrawText(ossV.str(), GetPosition().x - (numWidth / 2) , GetPosition().y - TextOffset);

    std::ostringstream ossA;
    ossA << mAmps;
    graphics->GetTextExtent(ossA.str(), &numWidth, &h);
    graphics->DrawText(ossA.str(), GetPosition().x - (numWidth / 2) , GetPosition().y - (TextOffset - 25));

}

void ZeroPointModule::Update(double elapsed)
{
    Component::Update(elapsed);
}

void ZeroPointModule::SetTime(double time)
{
    Power(ZPMVoltage);
}

double ZeroPointModule::Power(double voltage)
{
    mAmps = mSource.Power(voltage);

    return 0;
}


