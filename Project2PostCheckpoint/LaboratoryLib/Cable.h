/**
 * @file Cable.h
 * @author Jacob Stacy
 *
 *
 */

#ifndef CANADIANEXPERIENCE_CABLE_H
#define CANADIANEXPERIENCE_CABLE_H

class Clamp;

#include "Component.h"
#include "PowerSource.h"
#include "PowerSink.h"

/**
 * Cable Class
 */
class Cable : public Component{
private:

    /// Beizier Ends
    std::vector<std::shared_ptr<Clamp>> mEnds;

    /// Power Source
    std::shared_ptr<PowerSource> mSource;

    /// Power Sink
    PowerSink* mSink;

public:

    Cable(const std::wstring &name, const std::wstring &imageDir, std::shared_ptr<PowerSource> source, PowerSink* sink, double speedSource, double speedSink);

    /// Copy Constructor (Disabled)
    Cable(const Cable &) = delete;
    /// Assignment Operator (Disabled)
    void operator=(const Cable &) = delete;

    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;

    /**
     * Powers
     * @param voltage Volts
     * @return Amps
     */
    double Power(double voltage) override { return mSource->Power(voltage);}

    void AddClamp(std::shared_ptr<Clamp> clamp);


    /**
     * Get Source
     * @return Source
     */
    std::shared_ptr<PowerSource> GetSource () { return mSource; }

    /**
     * Get Sink
     * @return Sink
     */
    PowerSink* GetSink () {return mSink; }




};

#endif //CANADIANEXPERIENCE_CABLE_H
