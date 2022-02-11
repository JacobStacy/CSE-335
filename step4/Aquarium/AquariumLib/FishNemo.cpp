/**
 * @file FishNemo.cpp
 * @author Jacob Stacy
 */

#include "pch.h"
#include "FishNemo.h"
#include "Aquarium.h"
#include <string>

using namespace std;

/// Fish filename
const wstring FishNemoImageName = L"images/nemo.png";

/// Maximum speed in the X direction in
/// in pixels per second
const double MaxSpeedX = 200;

/// Minimum speed in the X direction in
/// pixels per second
const double MinSpeedX = 140;

/// Maximum speed in the Y direction in
/// in pixels per second
const double MaxSpeedY = 555;

/// Minimum speed in the X direction in
/// pixels per second
const double MinSpeedY = 10;

/**
 * Constructor
 * @param aquarium Aquarium this fish is a member of
 */
FishNemo::FishNemo(Aquarium *aquarium) : Fish(aquarium, FishNemoImageName)
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
void FishNemo::Spawn(Aquarium* aquarium)
{
    auto fish = make_shared<FishNemo>(aquarium);
    aquarium->Add(fish);
}

/**
 * Save this fish to an XML node
 * @param node The parent node we are going to be a child of
 * @return
 */
wxXmlNode* FishNemo::XmlSave(wxXmlNode* node)
{
    auto itemNode = Fish::XmlSave(node);

    itemNode->AddAttribute(L"type", L"nemo");

    return itemNode;
}