/**
 * @file DistributionPanel.h
 * @author Jacob Stacy
 *
 *
 */

#ifndef CANADIANEXPERIENCE_DISTRIBUTIONPANEL_H
#define CANADIANEXPERIENCE_DISTRIBUTIONPANEL_H


#include "Component.h"
#include "PowerSink.h"
#include "PowerSource.h"
#include "Polygon.h"

class DistributionPanel : public Component{
private:

    cse335::Polygon mPolygon;

    /// The PowerSink
    PowerSink mSink;

    /// The PowerSources
    std::vector<PowerSource> mSources;


public:

    DistributionPanel(const std::wstring& name, const std::wstring& image, const std::wstring& imageDir);

    /// Copy Constructor (Disabled)
    DistributionPanel(const DistributionPanel &) = delete;
    /// Assignment Operator (Disabled)
    void operator=(const DistributionPanel &) = delete;

    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;

    void Update(double elapsed) override;

    double Power(double voltage) override;

};

#endif //CANADIANEXPERIENCE_DISTRIBUTIONPANEL_H
