/**
 * @file LaboratoryFactoryTwo.cpp
 * @author Jacob Stacy
 */

#include "pch.h"

#include "LaboratoryFactoryTwo.h"
#include "ActualLaboratory.h"
#include "Shape.h"
#include "EquipmentRack.h"
#include "ZeroPointModule.h"

/// The Y position for the racks | website is down so need to change when I can look it up
const double RackY = -120;

using namespace std;

/**
 * Constructor
 * @param resourcesDir The directory that resources can be found in | probably need to make a member variable
 */
LaboratoryFactoryTwo::LaboratoryFactoryTwo(std::wstring resourcesDir) : mResourcesDir(resourcesDir)
{

}


/**
 * Creates Laboratory 1
 * @return
 */
std::shared_ptr<ActualLaboratory> LaboratoryFactoryTwo::CreateLaboratory()
{
    auto labTwo = make_shared<ActualLaboratory>();

    // The laboratory background image
    auto background = make_shared<Shape>(L"Background");
    background->GetPolygon()->SetImage(mResourcesDir + L"/images/laboratory.jpg");
    background->GetPolygon()->Rectangle(-600, 0);
    labTwo->AddComponent(background);

    return labTwo;
}
