/**
 * @file Switch.h
 * @author Jacob R. Stacy
 *
 *
 */

#ifndef CANADIANEXPERIENCE_SWITCH_H
#define CANADIANEXPERIENCE_SWITCH_H

#include "Polygon.h"
#include "Component.h"
#include "PowerSink.h"
#include "PowerSource.h"

/**
 * Switch Class
 */
class Switch : public Component{
private:

    /// If the switch is on or not
    bool mOn;

    /// Switch on Polygon | !!!!! Not in UML !!!!!
    cse335::Polygon mOnPolygon;

    /// Switch off Polygon | !!!!! Not in UML !!!!!
    cse335::Polygon mOffPolygon;

    /// Power Sink
    PowerSink mSink;

    /// On Source
    std::shared_ptr<PowerSource> mOnSource;

    /// Off Source
    std::shared_ptr<PowerSource> mOffSource;

    /// What side the connections are on, Left = True
    bool mSide = true;

public:

    Switch(const std::wstring& name, const std::wstring& imageDir, bool side);

    /// Copy Constructor (Disabled)
    Switch(const Switch &) = delete;
    /// Assignment Operator (Disabled)
    void operator=(const Switch &) = delete;

    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;

    void Update(double elapsed) override;

    double Power(double voltage) override;

    void XmlLoad(wxXmlNode* node) override;

    void Reset(int frame) override;

    /**
     * Get the sink object for this component
     * @return PowerSink object
     */
    PowerSink* GetSink() { return &mSink; }

    /**
     * Gets Top Source
     * @return Source
     */
    std::shared_ptr<PowerSource> GetOnSource() { return mOnSource; }

    /**
     * Gets Bottom Source
     * @return Source
     */
    std::shared_ptr<PowerSource> GetOffSource() { return mOffSource; }

};

#endif //CANADIANEXPERIENCE_SWITCH_H
