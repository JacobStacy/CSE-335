/**
 * @file DecorCastle.cpp
 * @author Jacob Stacy
 */

#include "pch.h"
#include "DecorCastle.h"
#include "Aquarium.h"
#include <string>

using namespace std;

/// Item filename
const wstring ItemImageName = L"images/castle.png";

/**
 * Constructor
 * @param aquarium Aquarium this fish is a member of
 */
DecorCastle::DecorCastle(Aquarium *aquarium) : Item(aquarium, ItemImageName)
{
}

/**
 * Spawns a copy of the fish
 * @param aquarium The aquarium the copy is added to
 */
void DecorCastle::Spawn(Aquarium* aquarium)
{
    auto fish = make_shared<DecorCastle>(aquarium);
    aquarium->Add(fish);
}

/**
 * Save this fish to an XML node
 * @param node The parent node we are going to be a child of
 * @return
 */
wxXmlNode* DecorCastle::XmlSave(wxXmlNode* node)
{
    auto itemNode = Item::XmlSave(node);

    itemNode->AddAttribute(L"type", L"castle");

    return itemNode;
}