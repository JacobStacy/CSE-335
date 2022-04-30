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

/**
 * DistributionPanel class
 */
class DistributionPanel : public Component{
private:

    /// Polygon
    cse335::Polygon mPolygon;

    /// The PowerSink
    PowerSink mSink;

    /// The PowerSources
    std::vector<std::shared_ptr<PowerSource>> mSources;


public:

    DistributionPanel(const std::wstring& name, const std::wstring& imageDir);

    /// Copy Constructor (Disabled)
    DistributionPanel(const DistributionPanel &) = delete;
    /// Assignment Operator (Disabled)
    void operator=(const DistributionPanel &) = delete;

    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;

    void Update(double elapsed) override;

    double Power(double voltage) override;

    /**
     * Get the sink object for this component
     * @return PowerSink object
     */
    PowerSink* GetSink() { return &mSink; }

    /**
     * Get Source
     * @param i Which Source
     * @return Source
     */
    std::shared_ptr<PowerSource> GetSource(int i) { return mSources[i]; }

    /**
     * Adds source
     * @param imageDir Dir
     * @param capacity Capacity
     */
    void AddSource (const std::wstring& imageDir, double capacity);

    void SetPosition(double x, double y) override;

};

#endif //CANADIANEXPERIENCE_DISTRIBUTIONPANEL_H
