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
    PowerSource mOnSource;

    /// Off Source
    PowerSource mOffSource;

public:

    Switch(const std::wstring& name, const std::wstring& imageDir,
            const std::wstring& onImage, const std::wstring& offImage, int xOffset);

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

    PowerSource* GetOnSource() { return &mOnSource; }

    PowerSource* GetOffSource() { return &mOffSource; }


//    /**
//     * Set the switch to on or off
//     * @param isOn Position it is being set to
//     */
//    void SetOn(bool isOn) { mOn = isOn; }

};

#endif //CANADIANEXPERIENCE_SWITCH_H
