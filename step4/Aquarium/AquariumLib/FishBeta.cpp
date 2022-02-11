/**
 * @file FishBeta.cpp
 * @author Jacob Stacy
 */

#include "pch.h"
#include "FishBeta.h"
#include "Aquarium.h"
#include <string>

using namespace std;

/// Fish filename
const wstring FishBetaImageName = L"images/beta.png";

/// Maximum speed in the X direction in
/// in pixels per second
const double MaxSpeedX = 101;

/// Minimum speed in the X direction in
/// pixels per second
const double MinSpeedX = 41;

/// Maximum speed in the Y direction in
/// in pixels per second
const double MaxSpeedY = 26;

/// Minimum speed in the X direction in
/// pixels per second
const double MinSpeedY = 11;

/**
 * Constructor
 * @param aquarium Aquarium this fish is a member of
 */
FishBeta::FishBeta(Aquarium *aquarium) : Fish(aquarium, FishBetaImageName)
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
void FishBeta::Spawn(Aquarium* aquarium)
{
    auto fish = make_shared<FishBeta>(aquarium);
    aquarium->Add(fish);
}

/**
 * Save this fish to an XML node
 * @param node The parent node we are going to be a child of
 * @return
 */
wxXmlNode* FishBeta::XmlSave(wxXmlNode* node)
{
    auto itemNode = Fish::XmlSave(node);

    itemNode->AddAttribute(L"type", L"beta");

    return itemNode;
}