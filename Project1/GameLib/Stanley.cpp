/**
 * @file Stanley.cpp
 * @author Kurt LaBlanc
 */

#include "pch.h"
#include "Stanley.h"
#include <string>
#include "Game.h"
#include "Vector.h"

using namespace std;

/**
 * Constructor
 * @param game The game we are in
 * @param bitmap The bitmap we use for Stanley
 */
Stanley::Stanley(Game* game,
        std::shared_ptr<wxBitmap> bitmap) : Item(game, bitmap)
{
}

/**
 * Test for collection between an item and another item
 * @param item item that we are seeing if we collided with
 * @return whether we have collided or not
 */
bool Stanley::CollisionTest(Item * item)
{
    if (hit)
    {   // Make sure it doesn't update the level twice
        return false;
    }

    if (Item::CollisionTest(item))
    {
        mText = true;
        GetGame()->UpTuition();
        Vector newV(10, -1000);
        mTP = GetY();
        mV = newV;
        hit = true;
    }
    return false; // return true only if you want stanley to stop moving when hit
}

/**
 * Makes Stanley fly away when he's hit
 * @param elapsed
 */
void Stanley::Update(double elapsed)
{
    mTP = mTP + mV.Y() * elapsed;
    Item::SetLocation(GetX(), GetY() - mV.Y() * elapsed);
}

/**
 * Incorporating text drawing onto the text when colliding with stanley
 * @param gc
 */
void Stanley::Draw(wxGraphicsContext* gc)
{
    Item::Draw(gc);
    wxFont font(wxSize(0, mTSize), wxFONTFAMILY_SWISS,
            wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);
    if(mText)
    {
        gc->SetFont(font, wxColour(0, 150, 0));
        gc->DrawText(L"Tuition Increase!", GetX(), mTP);
        mTSize+=5;
    }
}
