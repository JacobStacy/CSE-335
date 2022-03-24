/**
 * @file Door.cpp
 * @author Jacob Stacy
 */

#include "pch.h"
#include "Game.h"
#include "Door.h"
#include <string>

using namespace std;

/// Collision distance for the door in pixels
const double CollisionDistance = 20;

/**
 * Constructor
 * @param game
 * @param bitmap
 */
Door::Door(Game *game, std::shared_ptr<wxBitmap> bitmap) : Item(game, bitmap)
{
}

/**
 * Test for collection between an item and another item
 * @param item item that we are seeing if we collided with
 * @return whether we have collided or not
 */
bool Door::CollisionTest(Item* item)
{
    if (hit)
    {   // Make sure it doesn't update the level twice
        return false;
    }


    if (Item::CollisionTest(item))
    {
        // Collision for door is different
        double dx = item->GetX() - GetX();
        double dy = item->GetY() - GetY();
        double distance = sqrt(dx * dx + dy * dy);
        if (distance < CollisionDistance)
        {
            hit = true;
            GetGame()->NextLevel();
        }
    }
    return false; // return true only if you want sparty gnome to stop moving when hit
}
