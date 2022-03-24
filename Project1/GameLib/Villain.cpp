/**
 * @file Villain.cpp
 * @author Aref Zeitoun and John Landers
 */

#include "pch.h"
#include "Villain.h"
#include "Game.h"
#include <string>

using namespace std;

/// Distance of Movement
const double BounceDistance = 300;

/**
 * Constructor for villain class
 */
Villain::Villain(Game* game, std::shared_ptr<wxBitmap> bitmap) : Item(game, bitmap)
{
}


/**
 * Test for collection between an item and another item
 * @param item item that we are seeing if we collided with
 * @return whether we have collided or not
 */
bool Villain::CollisionTest(Item *item)
{
    if (Item::CollisionTest(item)) {
        auto game = GetGame();
        game->Restart();
        return true;
    }
    return false; // return true only if you want sparty gnome to stop moving when hit
}

/**
 * Load the attributes for an item node.
 *
 * This is the  base class version that loads the attributes
 * common to all items. Override this to load custom attributes
 * for specific items.
 * @param node XML node to load villain data from
 */
void Villain::XmlLoad(wxXmlNode *node)
{
    Item::XmlLoad(node);

    mTop = GetY() - BounceDistance;

    mBottom = GetY();
}

/**
 * Handle updates in real-time for villains
 * @param elapsed Time elapsed since last call
 */
void Villain::Update(double elapsed)
{
    double movement = mSpeed * elapsed;

    // Update villain location
    SetLocation(GetX(), GetY() + movement);

    // Change direction if needed
    if (GetY() <= mTop)
    {
        SetLocation(GetX(), mTop + 1);
        mSpeed = -mSpeed;
    } else if (GetY() >= mBottom)
    {
        SetLocation(GetX(), mBottom - 1);
        mSpeed = -mSpeed;
    }
}



