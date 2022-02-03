/**
 * @file Aquarium.cpp
 * @author Jacob Stacy
 */
#ifdef WIN32
#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>
#endif

#include "Aquarium.h"
#include "FishBeta.h"
#include "FishCarp.h"
#include "FishNemo.h"
#include <algorithm>

using namespace std;

/// Initial fish X location
const int InitialX = 200;

/// Initial fish Y location
const int InitialY = 200;

/// Fish X offset
const int OffX = 10;

/// Fish Y offset
const int OffY = 10;

/// Tolerance for being on top of another item
const double Tolerance = 1;

/**
 * Add an item to the aquarium
 * @param item New item to add
 */
void Aquarium::Add(std::shared_ptr<Item> item)
{
    item->SetLocation(InitialX, InitialY);

    for (auto currentItem : mItems) {
        if(item->DistanceTo(currentItem) < Tolerance) {
            item->SetLocation(item->GetX() + OffX, item->GetY() + OffY);
        }
    }

    mItems.push_back(item);
}

/**
 * Draw the aquarium
 * @param dc The device context to draw on
 */
void Aquarium::OnDraw(wxDC *dc)
{
    #ifdef WIN32
    _CrtSetDbgFlag ( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF );
    #endif

    dc->DrawBitmap(*mBackground, 0, 0);

    wxFont font(wxSize(0, 20),
            wxFONTFAMILY_SWISS,
            wxFONTSTYLE_NORMAL,
            wxFONTWEIGHT_NORMAL);
    dc->SetFont(font);
    dc->SetTextForeground(wxColour(0, 64, 0));
    dc->DrawText(L"Under the Sea!", 10, 10);

    for (auto item : mItems)
    {
        item->Draw(dc);
    }
}

/**
 * Aquarium Constructor
 */
Aquarium::Aquarium()
{
    mBackground = make_unique<wxBitmap>(
            L"images/background1.png", wxBITMAP_TYPE_ANY);
}

/**
 * Test an x,y click location to see if it clicked
 * on some item in the aquarium.
 * @param x X location in pixels
 * @param y Y location in pixels
 * @returns Pointer to item we clicked on or nullptr if none.
*/
std::shared_ptr<Item> Aquarium::HitTest(int x, int y)
{
    for (auto i = mItems.rbegin(); i != mItems.rend();  i++)
    {
        if ((*i)->HitTest(x, y))
        {
            return *i;
        }
    }

    return  nullptr;
}

/**
* Moves Item to the top of mItems
 * @param item Item that is moved
*/
void Aquarium::Top(shared_ptr<Item> item)
{
    auto loc = find(begin(mItems), end(mItems), item);

    if (loc != end(mItems))
    {
        mItems.erase(loc);
    }

    mItems.push_back(item);
}

/**
 * Gets the closest item to an item
 */
std::shared_ptr<Item> Aquarium::GetClosestTo(std::shared_ptr<Item> item)
{
    double distance = 0;
    std::shared_ptr<Item> closest = nullptr;
    for (const auto & currentItem : mItems)
    {
        if (currentItem != item)
        {
            double distanceFrom = item->DistanceTo(currentItem);
            if (distanceFrom <= distance || closest == nullptr)
            {
                distance = distanceFrom;
                closest = currentItem;
            }
        }
    }

    return closest;
}