/**
 * @file LaboratoryAdapter.cpp
 * @author Jacob Stacy
 */

#include "pch.h"

#include "LaboratoryAdapter.h"
#include <laboratory-api.h>
#include "Timeline.h"

/**
 * Constructor
 * @param name Name
 */
LaboratoryAdapter::LaboratoryAdapter(const std::wstring& name) :Drawable(name)
{
    LaboratoryFactory labFactory(L"LaboratoryLib/resources");

    mLaboratory = labFactory.CreateLaboratory();
}

/**
 * Draws Laboratory
 * @param graphics Graphics
 */
void LaboratoryAdapter::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    int currentFrame = mTimeline->GetCurrentFrame();

    mLaboratory->SetLaboratoryFrame(0);

    if (currentFrame >= mFrame)
    {
        mLaboratory->SetLaboratoryFrame(currentFrame - mFrame);
    }

    mLaboratory->SetLocation(wxPoint (mCurrentPosition.x, mCurrentPosition.y));
    mLaboratory->DrawLaboratory(graphics);
}

/**
 * Set Timeline
 * @param timeline New Timeline
 */
void LaboratoryAdapter::SetTimeline(Timeline* timeline)
{
    Drawable::SetTimeline(timeline);
    mTimeline = timeline;
}

/**
 * Shows the Dialog box
 * @param mainFrame Main frame
 * @return if ok has been pressed
 */
int LaboratoryAdapter::GetDialog(wxWindow* mainFrame)
{
    LaboratoryDialog dialog(mainFrame, mLaboratory);

    if(dialog.ShowModal() != wxID_OK)
    {
        return 0;
    }

    return 1;
}




