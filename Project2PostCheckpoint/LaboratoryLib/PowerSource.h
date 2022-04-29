/**
 * @file PowerSource.h
 * @author Jacob Stacy
 *
 *
 */

#ifndef CANADIANEXPERIENCE_POWERSOURCE_H
#define CANADIANEXPERIENCE_POWERSOURCE_H

class PowerSink;
class Component;

/**
 * The class for our PowerSource Object
 */
class PowerSource {
private:

    /// Power for the source
    double mPower;

    /// The postition of the PowerSource
    wxPoint mPosition;

    PowerSink* mSink = nullptr;

    std::wstring mImageDir;

    double mCapacity;


public:

    /// Default constructor (disabled)
    PowerSource() = delete;

    /// Copy constructor (disabled)
    PowerSource(const PowerSource &) = delete;

    /// Assignment operator
    void operator=(const PowerSource &) = delete;

    PowerSource(Component* parent, std::wstring imageDir, double capacity) : mImageDir(imageDir), mCapacity(capacity) {}
    
    double Power(double voltage);

    /**
     * Sets the sink for the source
     * @param sink Sink being set
     */
    void SetSink(PowerSink* sink) { mSink = sink; }

    void SetPosition(double x, double y) { mPosition.x = x; mPosition.y = y; }

    void Draw(std::shared_ptr<wxGraphicsContext> graphics, double x, double y, double rotation);
};

#endif //CANADIANEXPERIENCE_POWERSOURCE_H
