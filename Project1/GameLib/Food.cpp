/**
 * @file Food.cpp
 * @author Kurt LaBlanc
 */

#include "pch.h"
#include "Food.h"
#include "Game.h"
#include <string>
#include "Vector.h"
using namespace std;

/**
 * Constructor
 * @param game Game this Food Item is a member of
 * @param bitmap The bitmap we use for the food
 */
Food::Food(Game *game, std::shared_ptr<wxBitmap> bitmap) : Item(game, bitmap)
{
}

/**
 * Test for collection between an item and another item
 * @param item item that we are seeing if we collided with
 * @return whether we have collided or not
 */
bool Food::CollisionTest(Item* item)
{
    if (Item::CollisionTest(item) && !mText)
    {
        mText = true;
        GetGame()->IncreaseSpeed();
        Vector newV(10, -1000);
        mV = newV;
    }
    return false; // return true only if you want sparty gnome to stop moving when hit
}
/**
 * Hot dog flies away on contact
 * @param elapsed
 */
void Food::Update(double elapsed)
{
    Item::SetLocation(GetX() + mV.X() * elapsed, GetY() + mV.Y() * elapsed);
}

/**
 * Incorporating text drawing onto of hotdog
 * @param gc
 */
void Food::Draw(wxGraphicsContext* gc)
{
    Item::Draw(gc);
   wxFont font(wxSize(0, 25), wxFONTFAMILY_SWISS,
           wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);
   if(mText)
   {
       gc->SetFont(font, *wxRED);
       gc->DrawText(L"YUMMY!", GetX(), GetY() - 50);
   }
}
