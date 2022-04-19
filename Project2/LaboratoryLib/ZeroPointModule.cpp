/**
 * @file ZeroPointModule.cpp
 * @author Jacob Stacy
 */

#include "pch.h"

#include <sstream>

#include "ZeroPointModule.h"

const double TextOffset = 80;

/**
 * Constructor
 * @param name Name
 */
ZeroPointModule::ZeroPointModule(const std::wstring& name) : Component(name)
{
    mOrigin.x = 0;
    mOrigin.y = 0;

    mAmps = 0;
}

void ZeroPointModule::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    mPolygon.DrawPolygon(graphics, mOrigin.x, mOrigin.y); // Replace with visual shape

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
    graphics->DrawText(ossV.str(), mOrigin.x - (numWidth / 2) , mOrigin.y - TextOffset);

    std::ostringstream ossA;
    ossA << mAmps;
    graphics->GetTextExtent(ossA.str(), &numWidth, &h);
    graphics->DrawText(ossA.str(), mOrigin.x - (numWidth / 2) , mOrigin.y - (TextOffset - 25));

}

void ZeroPointModule::Update(double elapsed)
{
    Component::Update(elapsed);
}

double ZeroPointModule::Power(double voltage)
{
    return Component::Power(voltage);
}

void ZeroPointModule::XmlLoad(wxXmlNode node)
{
    Component::XmlLoad(node);
}

void ZeroPointModule::XmlEvent(wxXmlNode node)
{
    Component::XmlEvent(node);
}

void ZeroPointModule::SetTime(double time)
{
    Component::SetTime(time);
}


