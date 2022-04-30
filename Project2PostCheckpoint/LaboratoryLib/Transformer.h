/**
 * @file Transformer.h
 * @author Jacob Stacy
 *
 *
 */

#ifndef CANADIANEXPERIENCE_Transformer_H
#define CANADIANEXPERIENCE_Transformer_H

#include "Polygon.h"
#include "Component.h"
#include "PowerSource.h"
#include "PowerSink.h"
#include "Sparky.h"

/**
 * Transformer Class
 */
class Transformer : public Component{
private:

    /// Polygon
    cse335::Polygon mPolygon;

    /// Power Sink
    PowerSink mSink;

    /// Ration
    double mStep;

    /// Power Source
    std::shared_ptr<PowerSource> mSource;

public:

    Transformer(const std::wstring& name, const std::wstring& imageDir, double step);

    /// Copy Constructor (Disabled)
    Transformer(const Transformer &) = delete;
    /// Assignment Operator (Disabled)
    void operator=(const Transformer &) = delete;

    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;

    void SetTime(double time) override;

    double Power(double voltage) override;

    void SetPosition(double x, double y) override;

    /**
     * Gets Sink
     * @return Sink
     */
    PowerSink* GetSink() { return &mSink; }

    /**
     * Gets Source
     * @return Source
     */
    std::shared_ptr<PowerSource> GetSource() { return mSource; }



};

#endif //CANADIANEXPERIENCE_Transformer_H


