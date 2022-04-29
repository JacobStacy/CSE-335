/**
 * @file Orbs.h
 * @author Jacob Stacy
 *
 *
 */

#ifndef CANADIANEXPERIENCE_ORBS_H
#define CANADIANEXPERIENCE_ORBS_H

#include "Component.h"
#include "Polygon.h"
#include "MotionSink.h"
#include "PowerSink.h"
#include "Sparky.h"

class Orbs : public Component{
private:

    cse335::Polygon mPolygon;

    double mMovement = 0;

    MotionSink mMotionSink;

    PowerSink mPowerSink;

    cse335::Sparky mSparky;

    double mVoltage;

public:

    Orbs(const std::wstring& name, const std::wstring& imageDir, const std::wstring& image);

    /// Copy Constructor (Disabled)
    Orbs(const Orbs &) = delete;
    /// Assignment Operator (Disabled)
    void operator=(const Orbs &) = delete;

    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;

    void SetTime(double time) override;

    void XmlLoad(wxXmlNode* node) override;

    void Reset(int frame) override;

    void Update(double position) override;

    double Power(double voltage) override;

    MotionSink* GetMotionSink() { return &mMotionSink; }

    PowerSink* GetPowerSink() { return &mPowerSink; }

};

#endif //CANADIANEXPERIENCE_ORBS_H
