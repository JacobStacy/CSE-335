/**
 * @file Light.h
 * @author Jacob Stacy
 *
 *
 */

#ifndef CANADIANEXPERIENCE_LIGHT_H
#define CANADIANEXPERIENCE_LIGHT_H


#include "Polygon.h"
#include "Component.h"
#include "PowerSink.h"

/**
 * The class for the Light Object
 */
class Light : public Component{
private:

    bool mOn;

    cse335::Polygon mOnPolygon;
    cse335::Polygon mOffPolygon;

    /// The power sink for this Light
    PowerSink mSink;

//    /// Current Volatge of the light | !!!! NOT IN UML !!!!!
//    double mVolage = 0.0;
    
public:

    Light(const std::wstring& name, const std::wstring& imageDir, const std::wstring& onImage, const std::wstring& offImage, int xOffset);

    /// Copy Constructor (Disabled)
    Light(const Light &) = delete;
    /// Assignment Operator (Disabled)
    void operator=(const Light &) = delete;

    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;

    void Update(double elapsed) override;

    double Power(double voltage) override;

    /**
     * Get the sink object for this component
     * @return PowerSink object
     */
    PowerSink* GetSink() { return &mSink; }

};

#endif //CANADIANEXPERIENCE_LIGHT_H
