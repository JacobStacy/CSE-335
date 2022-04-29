/**
 * @file ZeroPointModule.h
 * @author Jacob Stacy
 *
 *
 */

#ifndef CANADIANEXPERIENCE_ZEROPOINTMODULE_H
#define CANADIANEXPERIENCE_ZEROPOINTMODULE_H


#include "Polygon.h"
#include "Component.h"
#include "PowerSource.h"

/**
 * Class for ZPM object
 */
class ZeroPointModule : public Component{
private:

    /// The Polygon for ZPM | !!!! NOT IN UML !!!!!
    cse335::Polygon mPolygon;

    
    /// ZPM's Volage
    double mVoltage = 1.0;
    
    /// ZPM's Amp Draw
    double mAmps;

    /// The power source for this ZPM
    PowerSource mSource;

public:

    ZeroPointModule(const std::wstring &name, const std::wstring& imageDir);

    /// Copy Constructor (Disabled)
    ZeroPointModule(const ZeroPointModule &) = delete;
    /// Assignment Operator (Disabled)
    void operator=(const ZeroPointModule &) = delete;
    
    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;
    
    void Update(double elapsed) override;

    double Power(double voltage) override;

    void SetTime(double time) override;

    void Reset(int frame) override;

    cse335::Polygon* GetPolygon() { return &mPolygon; }

    /**
     * Get the source object for this component
     * @return PowerSource object
     */
    PowerSource* GetSource() { return &mSource; }

};

#endif //CANADIANEXPERIENCE_ZEROPOINTMODULE_H
