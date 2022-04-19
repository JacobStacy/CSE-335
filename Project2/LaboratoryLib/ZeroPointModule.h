/**
 * @file ZeroPointModule.h
 * @author Jacob Stacy
 *
 *
 */

#ifndef CANADIANEXPERIENCE_ZEROPOINTMODULE_H
#define CANADIANEXPERIENCE_ZEROPOINTMODULE_H

#include "Polygon.h"
#include "Component.h"

class ZeroPointModule : public Component{
private:

    /// The Polygon for ZPM | !!!! NOT IN UML !!!!!
    cse335::Polygon mPolygon;

    /// Origin for ZPM | !!!! NOT IN UML !!!!!
    wxPoint mOrigin;
    
    /// ZPM's Volage
    double mVoltage = 1.0;
    
    /// ZPM's Amp Draw
    double mAmps;

public:

    ZeroPointModule(const std::wstring &name);

    /// Copy Constructor (Disabled)
    ZeroPointModule(const ZeroPointModule &) = delete;
    /// Assignment Operator (Disabled)
    void operator=(const ZeroPointModule &) = delete;
    
    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;
    
    void Update(double elapsed) override;

    double Power(double voltage) override;

    void XmlLoad(wxXmlNode node) override;

    void XmlEvent(wxXmlNode node) override;

    void SetTime(double time) override;

    cse335::Polygon* GetPolygon() { return &mPolygon; }

    void SetOrigin(double x, double y) { mOrigin.x = x; mOrigin.y = y; }

};

#endif //CANADIANEXPERIENCE_ZEROPOINTMODULE_H
