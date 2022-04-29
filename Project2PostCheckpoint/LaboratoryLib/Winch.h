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

class Winch : public Component {
private:

    double mRotation = 0.0;

    double mPrevTime = 0.0;

    double mDuration = 0.0;

    MotionSource mSource;

    cse335::Polygon mBasePolygon;

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

    MotionSource* GetSource() { return &mSource; }

};

#endif //CANADIANEXPERIENCE_WINCH_H
