/**
 * @file LightningScreen.h
 * @author Jacob Stacy
 *
 *
 */

#ifndef CANADIANEXPERIENCE_LightningScreen_H
#define CANADIANEXPERIENCE_LightningScreen_H

#include "Polygon.h"
#include "Component.h"
#include "PowerSource.h"
#include "PowerSink.h"
#include "Sparky.h"

/**
 * Lightning Screen Class
 */
class LightningScreen : public Component{
private:

    /// Polygon
    cse335::Polygon mPolygon;

    /// Power Sink
    PowerSink mSink;

    /// Sparky
    cse335::Sparky mSparky1;

    /// Sparky
    cse335::Sparky mSparky2;

    /// Sparky
    cse335::Sparky mSparky3;

    /// Sparky
    cse335::Sparky mSparky4;

    /// Sparky
    cse335::Sparky mSparky5;

    /// Sparky
    cse335::Sparky mSparky6;

    /// Random number generator
    std::mt19937 mRnd;

    /// Random Seed
    unsigned int mSeed;

    /// Voltage
    double mVoltage = 0;

public:

    LightningScreen(const std::wstring& name, const std::wstring& ImageDir);

    /// Copy Constructor (Disabled)
    LightningScreen(const LightningScreen &) = delete;
    /// Assignment Operator (Disabled)
    void operator=(const LightningScreen &) = delete;

    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;

    void SetTime(double time) override;

    double Power(double voltage) override;

    void Reset(int frame) override;

    void SetPosition(double x, double y) override;

    /**
     * Gets Sink
     * @return Sink
     */
    PowerSink* GetSink() { return &mSink; }



};

#endif //CANADIANEXPERIENCE_LightningScreen_H


