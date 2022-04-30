/**
 * @file PowerSink.h
 * @author Jacob Stacy
 *
 *
 */

#ifndef CANADIANEXPERIENCE_POWERSINK_H
#define CANADIANEXPERIENCE_POWERSINK_H

class PowerSource;

#include "Component.h"
#include "Polygon.h"
#include "BezierEnd.h"

/**
 * The class for our PowerSink Object
 */
class PowerSink : public BezierEnd {
private:

    /// The Component the sink belongs to
    Component* mParent;

    /// Image Directory
    std::wstring mImageDir;

    /// Capacity of connector
    double mCapacity;

    /// Voltage | This is only for the challenge task
    double mVoltage = 0;

public:

    /// Default constructor (disabled)
    PowerSink() = delete;

    /// Copy constructor (disabled)
    PowerSink(const PowerSink &) = delete;

    /// Assignment operator
    void operator=(const PowerSink &) = delete;

    PowerSink(Component *parent, const std::wstring& imageDir, double capacity, wxPoint point, double rotation, double speed = 100);

    double Power(double voltage);

//    /**
//     * Sets the source for the sink
//     * @param source Source being set
//     */
//    void SetSource(PowerSource* source) { mSource = source; }


    /**
     * Gets Parent
     * @return Parent
     */
    Component* GetParent() { return mParent; }

    void Draw(std::shared_ptr<wxGraphicsContext> graphics, double x, double y, double rotation);

    /**
     * Get Voltage | Only for challenge task
     * @return Voltage
     */
    double GetVoltage() { return mVoltage;}

    wxPoint GetPosition() override;
};

#endif //CANADIANEXPERIENCE_POWERSINK_H
