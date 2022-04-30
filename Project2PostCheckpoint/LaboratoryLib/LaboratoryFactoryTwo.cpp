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
#include "Light.h"
#include "Switch.h"
#include "Winch.h"
#include "Orbs.h"
#include "DistributionPanel.h"
#include "Cable.h"
#include "Clamp.h"
#include "Rheostat.h"
#include "Meter.h"
#include "Tubes.h"
#include "LightningScreen.h"
#include "Transformer.h"

/// Offset for drawing background
const double BackXOffset = -600;

/// Offset for drawing ZPM
const int ZpmXOffset = -50;

/// Offset for drawing ZPM
const double ZpmX = -550;

/// Offset for drawing Slots
const int SlotXOffset = -57;

/// Offset for drawing Equipment Racks
const double RackX = -350;

/// The Y position for the racks | website is down so need to change when I can look it up
const double RackY = -120;

/// The distance off the ground for slots
const double SlotYOffset = 15;

/// The Height of a U1 Rack in pixels
const int U1Height = 10;

/// The Height of a U2 Rack in pixels
const int U2Height = 21;

/// The Height of a U5 Rack in pixels
const int U5Height = 52;

/// The Height of a U2 Rack in pixels
const int U10Height = 104;

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

/// The X position for the Rheo
const double RheoX = 80;

/// The Y position for the Rheo
const double RheoY = 0;

/// Standard speed of beziers
const double StandardSpeed = 50;

/// The X position for the Screen
const double ScreenX = 120;

/// The Y position for the Screen
const double ScreenY = 0;

/// The X position for the Screen
const double TransformerX = 120;

/// The Y position for the Screen
const double TransformerY = 0;



using namespace std;

/**
 * Constructor
 * @param resourcesDir The directory that resources can be found in | probably need to make a member variable
 */
LaboratoryFactoryTwo::LaboratoryFactoryTwo(std::wstring resourcesDir) : mResourcesDir(resourcesDir)
{

}


/**
 * Creates Laboratory 2
 * @return
 */
std::shared_ptr<ActualLaboratory> LaboratoryFactoryTwo::CreateLaboratory()
{
    std::wstring imageDir = mResourcesDir + L"/images";


    auto labTwo = make_shared<ActualLaboratory>();

    // The laboratory background image
    auto background = make_shared<Shape>(L"Background");
    background->GetPolygon()->SetImage(mResourcesDir + L"/images/laboratory.jpg");
    background->GetPolygon()->BottomCenteredRectangle();

    // Rack 1 - the left rack
    auto rack1 = make_shared<EquipmentRack>(L"rack1", imageDir);
    rack1->SetOrigin(RackX, RackY);


    // The first slot
    auto blankUTwo1 = make_shared<Shape>(L"blankUTwo1");
    blankUTwo1->GetPolygon()->SetImage(mResourcesDir + L"/images/2u.png");
    blankUTwo1->GetPolygon()->BottomCenteredRectangle();
    blankUTwo1->SetOrigin(RackX, RackY - SlotYOffset);

    // The second slot
    auto blankUTwo2 = make_shared<Shape>(L"blankUTwo2");
    blankUTwo2->GetPolygon()->SetImage(mResourcesDir + L"/images/2u.png");
    blankUTwo2->GetPolygon()->Rectangle(SlotXOffset, 0);
    blankUTwo2->SetOrigin(RackX, RackY - SlotYOffset - U2Height);

    // The third slot
    auto blankUOne1 = make_shared<Shape>(L"blankUOne1");
    blankUOne1->GetPolygon()->SetImage(mResourcesDir + L"/images/1u.png");
    blankUOne1->GetPolygon()->Rectangle(SlotXOffset, 0);
    blankUOne1->SetOrigin(RackX, RackY - SlotYOffset - (U2Height * 2));



    // Rack 2 - the right rack
    auto rack2 = make_shared<EquipmentRack>(L"rack2", imageDir);
    rack2->SetOrigin(-RackX, RackY);

    // ZPM
    auto zeroPointModule = make_shared<ZeroPointModule>(L"ZPM", imageDir);
    zeroPointModule->GetPolygon()->SetImage(mResourcesDir + L"/images/zpm.png");
    zeroPointModule->GetPolygon()->Rectangle(ZpmXOffset, 0);
    zeroPointModule->SetPosition(ZpmX, RackY);

    // Light 1
    auto light1 = make_shared<Light>(L"", imageDir, mResourcesDir + L"/images/light1on.png",
            mResourcesDir + L"/images/light1.png", LightXOffset);
    light1->SetPosition(LightX, LightY);

//    // Light 2
//    auto light2 = make_shared<Light>(L"", imageDir, mResourcesDir + L"/images/light1on.png",
//            mResourcesDir + L"/images/light1.png", LightXOffset);
//    light2->SetPosition(-LightX, LightY);
//    labTwo->AddComponent(light2);

    // The U5 Background for switches
    auto switchUTen = make_shared<Shape>(L"blankUTwo2");
    switchUTen->GetPolygon()->SetImage(mResourcesDir + L"/images/10u.png");
    switchUTen->GetPolygon()->BottomCenteredRectangle();
    switchUTen->SetOrigin(RackX, RackY - SlotYOffset - (U2Height * 2) - U1Height);

    // The switch on the left side
    auto switch1 = make_shared<Switch>(L"switch1", imageDir, true);
    switch1->SetPosition(RackX - Switch1X, RackY - SlotYOffset - (U2Height * 2) - U1Height);

    // Screen
    auto screen = make_shared<LightningScreen>(L"screen", imageDir);
    screen->SetPosition(ScreenX, RackY + ScreenY);

    // Transformer
    auto optimusPrime = make_shared<Transformer>(L"screen", imageDir, 4);
    optimusPrime->SetPosition(-TransformerX, RackY + TransformerY);

    // The switch on the left side
    auto switch2 = make_shared<Switch>(L"switch2", imageDir, false);
    switch2->SetPosition(RackX + Switch1X, RackY - SlotYOffset - (U2Height * 2) - U1Height);

    // The winch
    auto winch = make_shared<Winch>(L"winch", mResourcesDir + L"/images/winch-12u-back.png", mResourcesDir + L"/images/winch-12u-wheel.png");
    winch->SetPosition(-RackX, RackY - SlotYOffset);

    // The orbs
    auto orbs = make_shared<Orbs>(L"orbs", imageDir, mResourcesDir + L"/images/orbs.png");
    orbs->SetPosition(OrbsX, OrbsY);

    // Distributor
    auto dist = make_shared<DistributionPanel>(L"dist",  imageDir);
    dist->SetPosition(RackX, RackY - SlotYOffset - (U2Height * 2) - U1Height - U10Height);

    //Rheostat
    auto rheo = make_shared<Rheostat>(L"rheostat", imageDir);
    rheo->SetPosition(ZpmX + RheoX, RackY);

    // Meter
    auto meter = make_shared<Meter>(L"meter", imageDir);
    meter->SetPosition(RackX, RackY - SlotYOffset - (U2Height * 2) - U1Height - U10Height - U5Height);

    // Blank Spacer
    auto blankUOne2 = make_shared<Shape>(L"blankUOne1");
    blankUOne2->GetPolygon()->SetImage(mResourcesDir + L"/images/1u.png");
    blankUOne2->GetPolygon()->BottomCenteredRectangle();
    blankUOne2->SetOrigin(RackX, RackY - SlotYOffset - (U2Height * 2) - U1Height - U10Height - (U5Height * 2));

    // Tubes
    auto tubes = make_shared<Tubes>(L"tubes", imageDir);
    tubes->SetPosition(RackX, RackY - SlotYOffset - (U2Height * 2) - (U1Height * 2) - U10Height - (U5Height * 2));



    //Connect winch to orbs
    winch->GetSource()->SetSink(orbs->GetMotionSink());

    auto cable1 = make_shared<Cable>(L"Cable", imageDir, zeroPointModule->GetSource(), rheo->GetSink(), 30, 30);
//    cable1->AddClamp(make_shared<Clamp>(0, 0, 0, 0));
//    cable1->AddClamp(make_shared<Clamp>(ZpmX + 100, RackY + 100, 40, .25));

    auto cable6 = make_shared<Cable>(L"Cable", imageDir, rheo->GetSource(), dist->GetSink(), StandardSpeed, StandardSpeed);
//    cable6->AddClamp(make_shared<Clamp>(0, 0, 0, 0));

    dist->AddSource(imageDir, 200);
    dist->AddSource(imageDir, 200);
    dist->AddSource(imageDir, 500);
    dist->AddSource(imageDir, 800);

    auto cable2 = make_shared<Cable>(L"Cable", imageDir, dist->GetSource(0), switch1->GetSink(), StandardSpeed, StandardSpeed);
//    cable2->AddClamp(make_shared<Clamp>(0, 0, 0, 0));
    cable2->AddClamp(make_shared<Clamp>(0, 0, StandardSpeed, StandardSpeed));

    auto cable3 = make_shared<Cable>(L"Cable", imageDir, dist->GetSource(1), switch2->GetSink(), StandardSpeed, StandardSpeed);
//    cable3->AddClamp(make_shared<Clamp>(0, 0, 0, 0));
    cable3->AddClamp(make_shared<Clamp>(0, 0, StandardSpeed, StandardSpeed));

    auto cable4 = make_shared<Cable>(L"Cable", imageDir, switch1->GetOnSource(), light1->GetSink(), StandardSpeed, StandardSpeed);
//    cable4->AddClamp(make_shared<Clamp>(0, 0, 0, 0));
    cable4->AddClamp(make_shared<Clamp>(0, 0, StandardSpeed, StandardSpeed));

    auto cable5 = make_shared<Cable>(L"Cable", imageDir, switch2->GetOnSource(), orbs->GetPowerSink(), StandardSpeed, StandardSpeed);
//    cable5->AddClamp(make_shared<Clamp>(0, 0, 0, 0));

    auto cable7 = make_shared<Cable>(L"Cable", imageDir, dist->GetSource(2), meter->GetSink(), StandardSpeed, StandardSpeed);
//    cable7->AddClamp(make_shared<Clamp>(0, 0, 0, 0));

    auto cable8 = make_shared<Cable>(L"Cable", imageDir, meter->GetSource(), tubes->GetLeftSink(), StandardSpeed,StandardSpeed);
//    cable8->AddClamp(make_shared<Clamp>(0, 0, 0, 0));
//
    auto cable9 = make_shared<Cable>(L"Cable", imageDir, dist->GetSource(3), optimusPrime->GetSink(), StandardSpeed,StandardSpeed);
//    cable8->AddClamp(make_shared<Clamp>(0, 0, 0, 0));

    auto cable10 = make_shared<Cable>(L"Cable", imageDir, optimusPrime->GetSource(), screen->GetSink(), StandardSpeed, StandardSpeed * 2);
//    cable8->AddClamp(make_shared<Clamp>(0, 0, 0, 0));

    // Load Animation Script
    labTwo->AddComponent(background);
    labTwo->AddComponent(rack1);
    labTwo->AddComponent(blankUTwo1);
    labTwo->AddComponent(blankUTwo2);
    labTwo->AddComponent(blankUOne1);
    labTwo->AddComponent(rack2);
    labTwo->AddComponent(zeroPointModule);
    labTwo->AddComponent(light1);
    labTwo->AddComponent(switchUTen);
    labTwo->AddComponent(switch1);
    labTwo->AddComponent(screen);
    labTwo->AddComponent(optimusPrime);
    labTwo->AddComponent(switch2);
    labTwo->AddComponent(winch);
    labTwo->AddComponent(dist);
    labTwo->AddComponent(rheo);
    labTwo->AddComponent(meter);
    labTwo->AddComponent(blankUOne2);
    labTwo->AddComponent(tubes);
    labTwo->AddComponent(cable1);
    labTwo->AddComponent(cable6);
    labTwo->AddComponent(cable2);
    labTwo->AddComponent(cable3);
    labTwo->AddComponent(cable4);
    labTwo->AddComponent(cable5);
    labTwo->AddComponent(cable7);
    labTwo->AddComponent(cable8);
    labTwo->AddComponent(cable9);
    labTwo->AddComponent(cable10);
    labTwo->AddComponent(orbs);

    labTwo->LoadScript(mResourcesDir + L"/scripts/laboratory2.xml");

    return labTwo;
}
