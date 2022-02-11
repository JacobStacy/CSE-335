/**
 * @file Fish.cpp
 * @author Jacob Stacy
 */

#include "pch.h"
#include "Fish.h"
#include "Aquarium.h"
#include <random>


/// Maximum speed in the X direction in
/// in pixels per second
const double MaxSpeedX = 100;

/// Minimum speed in the X direction in
/// pixels per second
const double MinSpeedX = 40;

/// Maximum speed in the Y direction in
/// in pixels per second
const double MaxSpeedY = 25;

/// Minimum speed in the X direction in
/// pixels per second
const double MinSpeedY = 10;

/// Distance from edge the fish will turn
const double edgeBuffer = 10;

/**
 * Constructor
 * @param aquarium The aquarium we are in
 * @param filename Filename for the image we use
 */
Fish::Fish(Aquarium *aquarium, const std::wstring &filename) :
        Item(aquarium, filename)
{
    std::uniform_real_distribution<> distributionX(MinSpeedX, MaxSpeedX);
    std::uniform_real_distribution<> distributionY(MinSpeedY, MaxSpeedY);
    mSpeedX = distributionX(aquarium->GetRandom());
    mSpeedY = distributionY(aquarium->GetRandom());
}

/**
 * Save this item to an XML node
 * @param node The parent node we are going to be a child of
 * @return wxXmlNode that we saved the item into
 */
wxXmlNode *Fish::XmlSave(wxXmlNode *node)
{
    auto itemNode = Item::XmlSave(node);
    itemNode->AddAttribute("speedX", wxString::FromDouble(mSpeedX));
    itemNode->AddAttribute("speedY", wxString::FromDouble(mSpeedY));

    return itemNode;
}

/**
 * Load the attributes for an item node.
 *
 * This is the  base class version that loads the attributes
 * common to all items. Override this to load custom attributes
 * for specific items.
 *
 * @param node The Xml node we are loading the item from
 */
void Fish::XmlLoad(wxXmlNode *node)
{
    Item::XmlLoad(node);
    node->GetAttribute(L"speedX", L"0").ToDouble(&mSpeedX);
    node->GetAttribute(L"speedY", L"0").ToDouble(&mSpeedY);
    if (mSpeedX < 0)
    {
        SetMirror(true);
    } else if (mSpeedX > 0)
    {
        SetMirror(false);
    }
}

/**
 * Handle updates in time of our fish
 *
 * This is called before we draw and allows us to
 * move our fish. We add our speed times the amount
 * of time that has elapsed.
 * @param elapsed Time elapsed since the class call
 */
void Fish::Update(double elapsed)
{

    SetLocation(GetX() + mSpeedX * elapsed,
            GetY() + mSpeedY * elapsed);

    if (mSpeedX > 0 && GetX() >= GetAquarium()->GetWidth() - edgeBuffer - (GetImageWidth() / 2))
    {
        mSpeedX = -mSpeedX;
        SetMirror(true);
    } else if (mSpeedX < 0 && GetX() <= 0 + edgeBuffer + (GetImageWidth() / 2)) {
        mSpeedX = -mSpeedX;
        SetMirror(false);
    }

    if (mSpeedY > 0 && GetY() >= GetAquarium()->GetHeight() - edgeBuffer - (GetImageHeight() / 2))
    {
        mSpeedY = -mSpeedY;
    } else if (mSpeedY < 0 && GetY() <= 0 + edgeBuffer + (GetImageHeight() / 2)) {
        mSpeedY = -mSpeedY;
    }
}

