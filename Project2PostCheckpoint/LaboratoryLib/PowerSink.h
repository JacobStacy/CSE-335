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

/**
 * The class for our PowerSink Object
 */
class PowerSink {
private:

    /// Power for the sink
    double mPower;

    /// The postition of the PowerSink
    wxPoint mPosition;

    /// The Component the sink belongs to
    Component* mParent;

    /// Source that the sink it connected to
    PowerSource* mSource;


public:

    /// Default constructor (disabled)
    PowerSink() = delete;

    /// Copy constructor (disabled)
    PowerSink(const PowerSink &) = delete;

    /// Assignment operator
    void operator=(const PowerSink &) = delete;

    PowerSink(Component *parent, std::wstring imageDir, double capacity);

    double Power(double voltage);

    /**
     * Sets the source for the sink
     * @param source Source being set
     */
    void SetSource(PowerSource* source) { mSource = source; }

    void SetPosition(double x, double y) { mPosition.x = x; mPosition.y = y; }

    Component* GetParent() { return mParent; }

};

#endif //CANADIANEXPERIENCE_POWERSINK_H
