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
#include "Light.h"
#include "Switch.h"
#include "Winch.h"
#include "Orbs.h"
#include "DistributionPanel.h"

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

/// X offset for the light
const int LightXOffset = -166;

/// The X position for the Light
const double LightX = 100;

/// The Y position for the Light
const double LightY = -600;

/// X offset for the light
const int SwitchXOffset = -23;

/// The X position for the Switch1
const double Switch1X = 25;

/// The Y position for the Switch1
const double Switch1Y = 20;

/// The X position for the Orbs
const double OrbsX = 0;

/// The Y position for the Switch1
const double OrbsY = -800;

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
    auto zeroPointModule = make_shared<ZeroPointModule>(L"ZPM", mResourcesDir + L"/images");
    zeroPointModule->GetPolygon()->SetImage(mResourcesDir + L"/images/zpm.png");
    zeroPointModule->GetPolygon()->Rectangle(ZpmXOffset, 0);
    zeroPointModule->SetPosition(ZpmX, RackY);
    labOne->AddComponent(zeroPointModule);

    // Light 1
    auto light1 = make_shared<Light>(L"", mResourcesDir + L"/images", mResourcesDir + L"/images/light1on.png",
            mResourcesDir + L"/images/light1.png", LightXOffset);
    light1->SetPosition(LightX, LightY);
    labOne->AddComponent(light1);

//    // Light 2
//    auto light2 = make_shared<Light>(L"", mResourcesDir + L"/images", mResourcesDir + L"/images/light1on.png",
//            mResourcesDir + L"/images/light1.png", LightXOffset);
//    light2->SetPosition(-LightX, LightY);
//    labOne->AddComponent(light2);

    // The switch on the left side
    auto switch1 = make_shared<Switch>(L"switch1", mResourcesDir + L"/images", mResourcesDir + L"/images/knifeswitch-on.png",
            mResourcesDir + L"/images/knifeswitch-off.png", SwitchXOffset);
    switch1->SetPosition(RackX - Switch1X, RackY - SlotYOffset - (U2Height * 2) - U1Height);
    labOne->AddComponent(switch1);

    // The switch on the left side
    auto switch2 = make_shared<Switch>(L"switch2", mResourcesDir + L"/images", mResourcesDir + L"/images/knifeswitch-on.png",
            mResourcesDir + L"/images/knifeswitch-off.png", SwitchXOffset);
    switch2->SetPosition(RackX + Switch1X, RackY - SlotYOffset - (U2Height * 2) - U1Height);
    labOne->AddComponent(switch2);

    // Connect ZPM to switch
    zeroPointModule->GetSource()->SetSink(switch1->GetSink());

    // Connect switch to lights
    switch1->GetOffSource()->SetSink(light1->GetSink());

    // The winch
    auto winch = make_shared<Winch>(L"winch", mResourcesDir + L"/images/winch-12u-back.png", mResourcesDir + L"/images/winch-12u-wheel.png");
    winch->SetPosition(-RackX, RackY - SlotYOffset);
    labOne->AddComponent(winch);

    // The orbs
    auto orbs = make_shared<Orbs>(L"orbs", mResourcesDir + L"/images", mResourcesDir + L"/images/orbs.png");
    orbs->SetPosition(OrbsX, OrbsY);
    labOne->AddComponent(orbs);

    //Connect winch to orbs
    winch->GetSource()->SetSink(orbs->GetMotionSink());

    switch1->GetOnSource()->SetSink(orbs->GetPowerSink());

    // Load Animation Script
    labOne->LoadScript(mResourcesDir + L"/scripts/laboratory1.xml");

    auto dist = make_shared<DistributionPanel>(L"dist", mResourcesDir + L"/images",  mResourcesDir + L"/images/dist-6u.png");


    return labOne;
}
