/**
 * @file MotionSink.h
 * @author Jacob Stacy
 *
 *
 */

#ifndef CANADIANEXPERIENCE_MOTIONSINK_H
#define CANADIANEXPERIENCE_MOTIONSINK_H

#include "MotionSource.h"
#include "Component.h"

/**
 * MotionSink
 */
class MotionSink {
private:

    /// The Component the sink belongs to
    Component* mParent;

public:

    /// Default constructor (disabled)
    MotionSink() = delete;

    /// Copy constructor (disabled)
    MotionSink(const MotionSink &) = delete;

    /// Assignment operator
    void operator=(const MotionSink &) = delete;

    /**
     * Constructor
     * @param parent Parent
     */
    MotionSink(Component *parent) : mParent(parent) {}

    void Move(double position);

    /**
     * Gets Parent
     * @return Parent
     */
    Component* GetParent() { return mParent; }


};

#endif //CANADIANEXPERIENCE_MOTIONSINK_H
