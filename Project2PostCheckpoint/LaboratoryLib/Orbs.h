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

/**
 * Orbs Class
 */
class Orbs : public Component{
private:

    /// Polygon
    cse335::Polygon mPolygon;

    /// Amount moved
    double mMovement = 0;

    /// Motion Sink
    MotionSink mMotionSink;

    /// PowerSink
    PowerSink mPowerSink;

    /// Sparks
    cse335::Sparky mSparky;

    /// Current Voltage
    double mVoltage;

public:

    Orbs(const std::wstring& name, const std::wstring& imageDir, const std::wstring& image);

    /// Copy Constructor (Disabled)
    Orbs(const Orbs &) = delete;
    /// Assignment Operator (Disabled)
    void operator=(const Orbs &) = delete;

    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;

    void SetTime(double time) override;

    void Reset(int frame) override;

    void Update(double position) override;

    double Power(double voltage) override;

    /**
     * Gets MotionSink
     * @return Sink
     */
    MotionSink* GetMotionSink() { return &mMotionSink; }

    /**
     * Gets PowerSink
     * @return Sink
     */
    PowerSink* GetPowerSink() { return &mPowerSink; }

    void SetPosition(double x, double y) override;
};

#endif //CANADIANEXPERIENCE_ORBS_H
