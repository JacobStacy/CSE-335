/**
 * @file Meter.h
 * @author Jacob Stacy
 *
 *
 */

#ifndef CANADIANEXPERIENCE_METER_H
#define CANADIANEXPERIENCE_METER_H

#include "Polygon.h"
#include "Component.h"
#include "PowerSource.h"
#include "PowerSink.h"

/**
 * Meter Class
 */
class Meter : public Component{
private:

    /// Polygon
    cse335::Polygon mPolygon;

//    /// Back Polygon
//    cse335::Polygon mBackPolygon;

//    /// Rotation
//    double mRotation = 0.0;
//
//    /// Previous Time
//    double mPrevTime = 0.0;

//    /// Duration of Animation
//    double mDuration = 0.0;
//
//    /// Resistance
//    double mResistance = 0;

    /// Voltage
    double mVoltage = 0;

    /// Current

    double mCurrent;

    /// PowerSource
    std::shared_ptr<PowerSource> mSource;

    /// PowerSink
    PowerSink mSink;

public:

    Meter(const std::wstring& name, const std::wstring& ImageDir);

    /// Copy Constructor (Disabled)
    Meter(const Meter &) = delete;
    /// Assignment Operator (Disabled)
    void operator=(const Meter &) = delete;

    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;

//    void SetTime(double time) override;
//
//    void XmlLoad(wxXmlNode* node) override;
//
//    void Reset(int frame) override;

    double Power(double voltage) override;

    void SetPosition(double x, double y) override;

    /**
     * Gets sink
     * @return Sink
     */
    PowerSink* GetSink() { return &mSink; }

    /**
     * Gets source
     * @return Source
     */
    std::shared_ptr<PowerSource> GetSource() { return mSource; }



};

#endif //CANADIANEXPERIENCE_METER_H


