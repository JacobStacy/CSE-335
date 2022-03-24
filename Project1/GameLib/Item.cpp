/**
 * @file Item.cpp
 * @author Jacob Stacy
 */

#include "pch.h"
#include "Item.h"
#include "Game.h"
#include <wx/graphics.h>

using namespace std;


/**
 * Constructor
 * @param game The game this item is a member of
 * @param bitmap The bitmap of the item
 */
Item::Item(Game *game, std::shared_ptr<wxBitmap> bitmap) : mGame(game)
{
    mItemBitmap = bitmap;
}

/**
 * Destructor
 */
Item::~Item()
{

}

/**
 * Draw this item
 * @param gc Device context to draw on
 */
void Item::Draw(wxGraphicsContext *gc)
{
    double wid = mItemBitmap->GetWidth();
    double hit = mItemBitmap->GetHeight();
    gc->DrawBitmap(*mItemBitmap,
            (GetX() - wid / 2),
            int(GetY() - hit / 2),
            int(wid), int(hit));
}


/**
 * Test for collection between an item and another item
 * @param item item that we are seeing if we collided with
 * @return whether we have collided or not
 */
bool Item::CollisionTest(Item * item)
{
    // For us
    auto ourTop = GetY() - GetHeight() / 2;
    auto ourRight = GetX() + GetWidth() / 2;
    auto ourBottom = GetY() + GetHeight() / 2;
    auto ourLeft = GetX() - GetWidth() / 2;

    // Border for the item
    auto itemTop = item->GetY() - item->GetHeight() / 2;
    auto itemRight = item->GetX() + item->GetWidth() / 2;
    auto itemBottom = item->GetY() + item->GetHeight() / 2;
    auto itemLeft = item->GetX() - item->GetWidth() / 2;

    // Test for all of the non-collision cases,
    // cases where there is a gap between the two items
    if (ourRight < itemLeft ||  // Completely to the left
            ourLeft > itemRight ||  // Completely to the right
            ourTop > itemBottom ||  // Completely below
            ourBottom < itemTop)    // Completely above
    {
        return false;
    }

    return true;

}

/**
 * Load the attributes for an item node.
 *
 * This is the  base class version that loads the attributes
 * common to all items. Override this to load custom attributes
 * for specific items.
 */
void Item::XmlLoad(wxXmlNode *node)
{
    node->GetAttribute(L"x").ToDouble(&mX);
    node->GetAttribute(L"y").ToDouble(&mY);
}
