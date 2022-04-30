/**
 * @file LaboratoryAdapter.h
 * @author Jacob Stacy
 *
 *
 */

#ifndef CANADIANEXPERIENCE_LABORATORYADAPTER_H
#define CANADIANEXPERIENCE_LABORATORYADAPTER_H


#include "Drawable.h"
#include <laboratory-api.h>

/**
 * LaboratoryAdapter
 */
class LaboratoryAdapter : public Drawable {
private:

    /// Lab
    std::shared_ptr<Laboratory> mLaboratory;

    /// Frame
    int mFrame = 0;

    /// Current Position
    wxPoint mCurrentPosition;

    /// Timeline
    Timeline* mTimeline = nullptr;

public:

    LaboratoryAdapter(const std::wstring& name);

    /// Copy Constructor (Disabled)
    LaboratoryAdapter(const LaboratoryAdapter &) = delete;
    /// Assignment Operator (Disabled)
    void operator=(const LaboratoryAdapter &) = delete;

    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;

    /**
     * Hit?
     * @param pos Postion
     * @return Hit?
     */
    bool HitTest(wxPoint pos) { return false; }

    void SetTimeline( Timeline* timeline) override;

    /**
     * Gets Lab Number
     * @return
     */
    int GetLaboratoryNumber() { return mLaboratory->GetLaboratoryNumber(); }

    /**
     * Set Lab Number
     * @param i Lab Number
     */
    void SetLaboratoryNumber(int i) { mLaboratory->SetLaboratoryNumber(i); }

    int GetDialog(wxWindow* mainFrame);

    /**
     * Gets Frame
     * @return Frame
     */
    int GetFrame() {return mFrame;}

    /**
     * Set Frame
     * @param frame Frame
     */
    void SetFrame(int frame) { mFrame = frame; }

    /**
     * Set Posititon
     * @param point Point
     */
    void SetLaboratoryPosition(wxPoint point) { mCurrentPosition = point; }



};

#endif //CANADIANEXPERIENCE_LABORATORYADAPTER_H
