/**
 * @file Money.cpp
 * @author matt wright, Jacob Stacy
 * Implementation of the money class
 */

#include "pch.h"
#include "Game.h"
#include "Money.h"
#include <string>

using namespace std;

/**
 * Constructor
 * @param game The game we are in
 * @param bitmap for the money
 * @param value The value of the Money object
 */
Money::Money(Game *game, std::shared_ptr<wxBitmap> bitmap, int value) : Item(game, bitmap)
{
    mValue = value;
}

/**
 * Test for collection between an item and another item
 * @param item item that we are seeing if we collided with
 * @return whether we have collided or not
 */
bool Money::CollisionTest(Item *item)
{
    if (Item::CollisionTest(item) && !mText)
    {
        mText = true;
        item->GetGame()->AddMoney(mValue * GetGame()->GetTuition());
        Vector newV(10, -1000);
        mV = newV;
    }

    return false;
}
/**
 * Makes money fly away when it's hit
 * @param elapsed
 */
void Money::Update(double elapsed)
{
    Item::SetLocation(GetX(), GetY() + mV.Y() * elapsed);
}
/**
 * Incorporating text drawing onto the money when collision
 * @param gc
 */
void Money::Draw(wxGraphicsContext* gc)
{
    Item::Draw(gc);
    wxFont font(wxSize(0, 25), wxFONTFAMILY_SWISS,
            wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);
    if(mText)
    {
        gc->SetFont(font, wxColour(24, 69, 59));
        gc->DrawText(L"$" + std::to_wstring(int(mValue * GetGame()->GetTuition())), GetX(), GetY() + 50);
    }
}
