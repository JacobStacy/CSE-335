/**
 * @file Tubes.h
 * @author Jacob Stacy
 *
 *
 */

#ifndef CANADIANEXPERIENCE_TUBES_H
#define CANADIANEXPERIENCE_TUBES_H

#include "Polygon.h"
#include "Component.h"
#include "PowerSource.h"
#include "PowerSink.h"

/**
 * Tubes Class
 */
class Tubes : public Component{
private:

    /// Polygon
    cse335::Polygon mBackPolygon;

    /// Polygon
    cse335::Polygon mLeftPolygon;

    /// Polygon
    cse335::Polygon mRightPolygon;

    /// Left Voltage
    double mLeftVoltage = 0;

    /// Right Voltage
    double mRightVoltage = 0;

    /// Left Power Sink
    PowerSink mSinkLeft;

    /// Left Power Sink
    PowerSink mSinkRight;

public:

    Tubes(const std::wstring& name, const std::wstring& ImageDir);

    /// Copy Constructor (Disabled)
    Tubes(const Tubes &) = delete;
    /// Assignment Operator (Disabled)
    void operator=(const Tubes &) = delete;

    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;

//    void SetTime(double time) override;
//
//    void XmlLoad(wxXmlNode* node) override;
//
    void Reset(int frame) override;

    double Power(double voltage) override;

    void SetPosition(double x, double y) override;

    /**
     * Gets Left Sink
     * @return Sink
     */
    PowerSink* GetLeftSink() { return &mSinkLeft; }

    /**
     * Gets Right Sink
     * @return Sink
     */
    PowerSink* GetRightSink() { return &mSinkRight; }



};

#endif //CANADIANEXPERIENCE_TUBES_H


