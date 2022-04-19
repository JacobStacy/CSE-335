/**
 * @file LaboratoryFactoryOne.cpp
 * @author Jacob Stacy
 */

#include "pch.h"

#include "LaboratoryFactoryOne.h"
#include "ActualLaboratory.h"
#include "Shape.h"
#include "EquipmentRack.h"
#include "ZeroPointModule.h"

/// The Y position for the racks | website is down so need to change when I can look it up
const double RackY = 0;

using namespace std;

/**
 * Constructor
 * @param resourcesDir The directory that resources can be found in | probably need to make a member variable
 */
LaboratoryFactoryOne::LaboratoryFactoryOne(std::wstring resourcesDir) : mResourcesDir(resourcesDir)
{

}


/**
 * Creates Laboratory 1
 * @return
 */
std::shared_ptr<ActualLaboratory> LaboratoryFactoryOne::CreateLaboratory()
{
    auto labOne = make_shared<ActualLaboratory>();

    // The laboratory background image
    auto background = make_shared<Shape>(L"Background");
    background->GetPolygon()->SetImage(mResourcesDir + L"/images/laboratory.jpg");
    background->GetPolygon()->Rectangle(-600, 0);
    labOne->AddComponent(background);

    // Rack 1 - the left rack
    auto rack1 = make_shared<EquipmentRack>(L"rack1", mResourcesDir + L"/images");
    rack1->SetOrigin(-300, RackY);
    labOne->AddComponent(rack1);

    // Rack 2 - the left rack
    auto rack2 = make_shared<EquipmentRack>(L"rack2", mResourcesDir + L"/images");
    rack2->SetOrigin(300, RackY);
    labOne->AddComponent(rack2);

    // ZPM
    auto zeroPointModule = make_shared<ZeroPointModule>(L"ZPM");
    zeroPointModule->GetPolygon()->SetImage(mResourcesDir + L"/images/zpm.png");
    zeroPointModule->GetPolygon()->Rectangle(-50, 0);
    labOne->AddComponent(zeroPointModule);
    return labOne;
}
