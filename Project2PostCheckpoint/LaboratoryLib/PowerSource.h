/**
 * @file PowerSource.h
 * @author Jacob Stacy
 *
 *
 */

#ifndef CANADIANEXPERIENCE_POWERSOURCE_H
#define CANADIANEXPERIENCE_POWERSOURCE_H

#include "BezierEnd.h"

class PowerSink;
class Component;

/**
 * The class for our PowerSource Object
 */
class PowerSource : public BezierEnd {
private:


    /// Sink connected to
    PowerSink* mSink = nullptr;

    /// Image Dir
    std::wstring mImageDir;

    /// Capacity
    double mCapacity;


public:

    /// Default constructor (disabled)
    PowerSource() = delete;

    /// Copy constructor (disabled)
    PowerSource(const PowerSource &) = delete;

    /// Assignment operator
    void operator=(const PowerSource &) = delete;

    PowerSource(Component* parent, std::wstring imageDir, double capacity, wxPoint point, double rotation, double speed = 100);
    
    double Power(double voltage);

    /**
     * Sets the sink for the source
     * @param sink Sink being set
     */
    void SetSink(PowerSink* sink) { mSink = sink; }

    void Draw(std::shared_ptr<wxGraphicsContext> graphics, double x, double y, double rotation);

    /**
     * Gets Capacity
     * @return Capacity
     */
    double GetCapacity() { return mCapacity; }

    wxPoint GetPosition() override;
};

#endif //CANADIANEXPERIENCE_POWERSOURCE_H
