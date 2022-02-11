/**
 * @file FishCarp.cpp
 * @author Jacob Stacy
 */

#include "pch.h"
#include "FishCarp.h"
#include "Aquarium.h"
#include <string>

using namespace std;

/// Fish filename
const wstring FishCarpImageName = L"images/magikarp.png";

/// Maximum speed in the X direction in
/// in pixels per second
const double MaxSpeedX = 1000;

/// Minimum speed in the X direction in
/// pixels per second
const double MinSpeedX = 4;

/// Maximum speed in the Y direction in
/// in pixels per second
const double MaxSpeedY = 288;

/// Minimum speed in the X direction in
/// pixels per second
const double MinSpeedY = 1;

/**
 * Constructor
 * @param aquarium Aquarium this fish is a member of
 */
FishCarp::FishCarp(Aquarium *aquarium) : Fish(aquarium, FishCarpImageName)
{
    std::uniform_real_distribution<> distributionX(MinSpeedX, MaxSpeedX);
    std::uniform_real_distribution<> distributionY(MinSpeedY, MaxSpeedY);
    Fish::SetSpeedX(distributionX(aquarium->GetRandom()));
    Fish::SetSpeedY(distributionX(aquarium->GetRandom()));
}

/**
 * Spawns a copy of the fish
 * @param aquarium The aquarium the copy is added to
 */
void FishCarp::Spawn(Aquarium* aquarium)
{
    auto fish = make_shared<FishCarp>(aquarium);
    aquarium->Add(fish);
}

/**
 * Save this fish to an XML node
 * @param node The parent node we are going to be a child of
 * @return
 */
wxXmlNode* FishCarp::XmlSave(wxXmlNode* node)
{
    auto itemNode = Fish::XmlSave(node);

    itemNode->AddAttribute(L"type", L"carp");

    return itemNode;
}

