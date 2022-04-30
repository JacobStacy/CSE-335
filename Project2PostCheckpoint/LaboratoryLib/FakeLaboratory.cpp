/**
 * @file FakeLaboratory.cpp
 * @author Jacob Stacy
 */

#include "pch.h"

#include "FakeLaboratory.h"
#include "ActualLaboratory.h"
#include "LaboratoryFactoryOne.h"
#include "LaboratoryFactoryTwo.h"

/**
 * Constructor
 * @param resourcesDir Directory containing the program resources
 */
FakeLaboratory::FakeLaboratory(std::wstring resourcesDir) : mResourcesDir(resourcesDir)
{
    SetLaboratoryNumber(1);
}

/**
 * Draws the Laboratory
 * @param graphics
 */
void FakeLaboratory::DrawLaboratory(std::shared_ptr<wxGraphicsContext> graphics)
{

    graphics->PushState();

    // Anything Draw in here will be offset by the lab location
    graphics->Translate(mX, mY);
    mLaboratory->DrawLaboratory(graphics);

    graphics->PopState();
}

/**
 * Set's the lab number
 * @param laboratory Lab number
 */
void FakeLaboratory::SetLaboratoryNumber(int laboratory)
{
    mCurrentLaboratory = laboratory;

    // Based on the number passed a laboratory will be created with its respective factory
    if (laboratory == 1)
    {
        auto factory = LaboratoryFactoryOne(mResourcesDir);
        mLaboratory = factory.CreateLaboratory();
    } else if (laboratory == 2)
    {
        auto factory = LaboratoryFactoryTwo(mResourcesDir);
        mLaboratory = factory.CreateLaboratory();
    }

    mLaboratory->Update(0);
}

/**
* Set the current laboratory animation frame
* @param frame Frame number
*/
void FakeLaboratory::SetLaboratoryFrame(int frame)
{
    if (frame < mFrame)
    {
        // We are going backwards in time,
        // reset to the beginning
        mFrame = -1;
        mLaboratory->Update(-1);
    }


    while (mFrame < frame)
    {
        mFrame++;
        mLaboratory->Update(GetLaboratoryTime());
    }

    //mLaboratory->Update(GetLaboratoryTime());
}
