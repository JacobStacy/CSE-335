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

/// Offset for drawing background
double BackXOffset = -600;

/// Offset for drawing ZPM
int ZpmXOffset = -50;

/// Offset for drawing ZPM
double ZpmX = -550;

/// Offset for drawing Slots
int SlotXOffset = -57;

/// Offset for drawing Equipment Racks
double RackX = -350;

/// The Y position for the racks | website is down so need to change when I can look it up
const double RackY = -120;

/// The distance off the ground for slots
const double SlotYOffset = 15;

/// The Height of a U1 Rack in pixels
const int U1Height = 10;

/// The Height of a U2 Rack in pixels
const int U2Height = 21;

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
    background->GetPolygon()->Rectangle(BackXOffset, 0);
    labOne->AddComponent(background);

    // Rack 1 - the left rack
    auto rack1 = make_shared<EquipmentRack>(L"rack1", mResourcesDir + L"/images");
    rack1->SetOrigin(RackX, RackY);
    labOne->AddComponent(rack1);


    // The first slot
    auto blankUTwo1 = make_shared<Shape>(L"blankUTwo1");
    blankUTwo1->GetPolygon()->SetImage(mResourcesDir + L"/images/2u.png");
    blankUTwo1->GetPolygon()->Rectangle(SlotXOffset, 0);
    blankUTwo1->SetOrigin(RackX, RackY - SlotYOffset);
    labOne->AddComponent(blankUTwo1);

    // The second slot
    auto blankUTwo2 = make_shared<Shape>(L"blankUTwo2");
    blankUTwo2->GetPolygon()->SetImage(mResourcesDir + L"/images/2u.png");
    blankUTwo2->GetPolygon()->Rectangle(SlotXOffset, 0);
    blankUTwo2->SetOrigin(RackX, RackY - SlotYOffset - U2Height);
    labOne->AddComponent(blankUTwo2);

    // The third slot
    auto blankUOne1 = make_shared<Shape>(L"blankUOne1");
    blankUOne1->GetPolygon()->SetImage(mResourcesDir + L"/images/1u.png");
    blankUOne1->GetPolygon()->Rectangle(SlotXOffset, 0);
    blankUOne1->SetOrigin(RackX, RackY - SlotYOffset - (U2Height * 2));
    labOne->AddComponent(blankUOne1);



    // Rack 2 - the right rack
    auto rack2 = make_shared<EquipmentRack>(L"rack2", mResourcesDir + L"/images");
    rack2->SetOrigin(-RackX, RackY);
    labOne->AddComponent(rack2);

    // ZPM
    auto zeroPointModule = make_shared<ZeroPointModule>(L"ZPM");
    zeroPointModule->GetPolygon()->SetImage(mResourcesDir + L"/images/zpm.png");
    zeroPointModule->GetPolygon()->Rectangle(ZpmXOffset, 0);
    zeroPointModule->SetOrigin(ZpmX, RackY);
    labOne->AddComponent(zeroPointModule);
    return labOne;
}
