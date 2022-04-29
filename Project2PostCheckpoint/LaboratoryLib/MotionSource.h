/**
 * @file MotionSource.h
 * @author Jacob Stacy
 *
 *
 */

#ifndef CANADIANEXPERIENCE_MOTIONSOURCE_H
#define CANADIANEXPERIENCE_MOTIONSOURCE_H

class MotionSink;
class Component;

class MotionSource {
private:

    MotionSink* mSink;

public:

    /// Default constructor (disabled)
    MotionSource() = delete;

    /// Copy constructor (disabled)
    MotionSource(const MotionSource &) = delete;

    /// Assignment operator
    void operator=(const MotionSource &) = delete;

    MotionSource(Component* parent) {}

    double Move(double time, double duration, double position);

    /**
     * Sets the sink for the source
     * @param sink Sink being set
     */
    void SetSink(MotionSink* sink) { mSink = sink; }

};

#endif //CANADIANEXPERIENCE_MOTIONSOURCE_H
