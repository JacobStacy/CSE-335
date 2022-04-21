/**
 * @file FakeLaboratory.h
 * @author Jacob Stacy
 *
 *
 */

#ifndef CANADIANEXPERIENCE_FAKELABORATORY_H
#define CANADIANEXPERIENCE_FAKELABORATORY_H

class ActualLaboratory;

#include "Laboratory.h"

class FakeLaboratory : public Laboratory{
private:

    /// The current frame of animation
    int mFrame = 0;

    /// The current laboratory being drawn
    int mCurrentLaboratory = 1;

    /// Current X position | maybe change to double
    int mX = 0;

    /// Current Y position | maybe change to double
    int mY = 0;

    /// Directory for resources | !!!! NOT IN UML !!!!!
    std::wstring mResourcesDir;

    /// Frame rate in frames per second | !!!! NOT IN UML !!!!!
    double mFrameRate = 30;

    /// The Actual Lab
    std::shared_ptr<ActualLaboratory> mLaboratory;

public:

    /// Copy Constructor (Disabled)
    FakeLaboratory(const FakeLaboratory &) = delete;
    /// Assignment Operator (Disabled)
    void operator=(const FakeLaboratory &) = delete;

    FakeLaboratory(std::wstring resourcesDir);


    void DrawLaboratory(std::shared_ptr<wxGraphicsContext> graphics) override;

    /**
     * Set the frame rate
     * @param rate New frame rate
     */
    void SetFrameRate(double rate) override { mFrameRate = rate; }

    /**
    * Set the current laboratory animation frame
    * @param frame Frame number
    */
    void SetLaboratoryFrame(int frame) override { mFrame = frame;}

    void SetLaboratoryNumber(int laboratory) override;

    /**
     * Gets the lab number
     * @return Lab Number
     */
    int GetLaboratoryNumber() override { return mCurrentLaboratory; }

    /**
     * Set the location of the lab
     * @param location New Location
     */
    void SetLocation(wxPoint location) override { mX = location.x; mY = location.y; }

    /**
     * Get location of lab
     * @return Location
     */
    wxPoint GetLocation() override { return wxPoint(mX, mY); }

    /**
     * Get the current lab time
     * @return
     */
    double GetLaboratoryTime() override { return mFrame / mFrameRate;}





};

#endif //CANADIANEXPERIENCE_FAKELABORATORY_H
