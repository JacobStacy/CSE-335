/**
 * @file Winch.h
 * @author Jacob Stacy
 *
 *
 */

#ifndef CANADIANEXPERIENCE_WINCH_H
#define CANADIANEXPERIENCE_WINCH_H

#include "Component.h"
#include "Polygon.h"
#include "MotionSource.h"

/**
 * Winch Class
 */
class Winch : public Component {
private:

    /// Rotation
    double mRotation = 0.0;

    /// Previous Time
    double mPrevTime = 0.0;

    /// Duration of Animation
    double mDuration = 0.0;

    /// Motion Source
    MotionSource mSource;

    /// Base Polygon
    cse335::Polygon mBasePolygon;

    /// Wheel Polygon
    cse335::Polygon mWheelPolygon;

public:

    Winch(const std::wstring& name, const std::wstring& backImage, const std::wstring& wheelImage);

    /// Copy Constructor (Disabled)
    Winch(const Winch &) = delete;
    /// Assignment Operator (Disabled)
    void operator=(const Winch &) = delete;

    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;

    void SetTime(double time) override;

    void XmlLoad(wxXmlNode* node) override;

    void Reset(int frame) override;

    /**
     * Returns the Source
     * @return Source
     */
    MotionSource* GetSource() { return &mSource; }

};

#endif //CANADIANEXPERIENCE_WINCH_H
