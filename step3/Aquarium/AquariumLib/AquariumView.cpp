/**
 * @file AquariumView.cpp
 * @author Jacob Stacy
 */

#include "AquariumView.h"
#include "pch.h"
#include "ids.h"
#include "FishBeta.h"
#include "FishCarp.h"
#include "FishNemo.h"
#include "FishMosquito.h"

#include <wx/dcbuffer.h>

using namespace std;


/**
 * Initialize the aquarium view class.
 * @param parent The parent window for this class
 */
void AquariumView::Initialize(wxFrame* parent)
{
    Create(parent, wxID_ANY);
    SetBackgroundColour(*wxWHITE);
    Bind(wxEVT_PAINT, &AquariumView::OnPaint, this);
    SetBackgroundStyle(wxBG_STYLE_PAINT);

    parent->Bind(wxEVT_COMMAND_MENU_SELECTED, &AquariumView::OnAddFishBetaFish, this, IDM_ADDFISHBETA);
    parent->Bind(wxEVT_COMMAND_MENU_SELECTED, &AquariumView::OnAddFishNemoFish, this, IDM_ADDFISHNEMO);
    parent->Bind(wxEVT_COMMAND_MENU_SELECTED, &AquariumView::OnAddFishCarpFish, this, IDM_ADDFISHCARP);
    parent->Bind(wxEVT_COMMAND_MENU_SELECTED, &AquariumView::OnAddFishMosquitoFish, this, IDM_ADDFISHMOSQUITO);

    Bind(wxEVT_LEFT_DOWN, &AquariumView::OnLeftDown, this);
    Bind(wxEVT_LEFT_UP, &AquariumView::OnLeftUp, this);
    Bind(wxEVT_MOTION, &AquariumView::OnMouseMove, this);

}

/**
 * Paint event, draws the window.
 * @param event Paint event object
 */
void AquariumView::OnPaint(wxPaintEvent& event)
{
    wxAutoBufferedPaintDC dc(this);

    wxBrush background(*wxWHITE);
    dc.SetBackground(background);
    dc.Clear();

    mAquarium.OnDraw(&dc);
}

/**
 * Menu handier for Add Fish>Beta Fish
 * @param event Mouse event
 */
void AquariumView::OnAddFishBetaFish(wxCommandEvent& event)
{
    auto fish = make_shared<FishBeta>(&mAquarium);
    mAquarium.Add(fish);
    Refresh();
}

/**
 * Menu handier for Add Fish>Nemo Fish
 * @param event Mouse event
 */
void AquariumView::OnAddFishNemoFish(wxCommandEvent& event)
{
    auto fish = make_shared<FishNemo>(&mAquarium);
    mAquarium.Add(fish);
    Refresh();
}

/**
 * Menu handier for Add Fish>Mosquito Fish
 * @param event Mouse event
 */
void AquariumView::OnAddFishMosquitoFish(wxCommandEvent& event)
{
    auto fish = make_shared<FishMosquito>(&mAquarium);
    mAquarium.Add(fish);
    Refresh();
}

/**
 * Menu handier for Add Fish>Carp Fish
 * @param event Mouse event
 */
void AquariumView::OnAddFishCarpFish(wxCommandEvent& event)
{
    auto fish = make_shared<FishCarp>(&mAquarium);
    mAquarium.Add(fish);
    Refresh();
}

/**
 * Handle the left mouse button down event
 * @param event
 */
void AquariumView::OnLeftDown(wxMouseEvent &event)
{
    mGrabbedItem = mAquarium.HitTest(event.GetX(), event.GetY());
    if (mGrabbedItem != nullptr)
    {
        mAquarium.Top(mGrabbedItem);
    }
}

/**
* Handle the left mouse button down event
* @param event
*/
void AquariumView::OnLeftUp(wxMouseEvent &event)
{
    OnMouseMove(event);
}

/// distance items will breed at
const double breedingDistance = 30;

/**
* Handle the mouse move event
* @param event
*/
void AquariumView::OnMouseMove(wxMouseEvent &event)
{
    // See if an item is currently being moved by the mouse
    if (mGrabbedItem != nullptr)
    {
        // If an item is being moved, we only continue to
        // move it while the left button is down.
        if (event.LeftIsDown())
        {
            mGrabbedItem->SetLocation(event.GetX(), event.GetY());

            auto closest = mAquarium.GetClosestTo(mGrabbedItem);


            if (closest != nullptr)
            {
                double distance = mGrabbedItem->DistanceTo(closest);
                if (distance < breedingDistance)
                {
                    if(mGrabbedItem->Breed(closest))
                    {
                        closest->Spawn(&mAquarium);
                    }
                } else
                {
                    mGrabbedItem->Breed(nullptr);
                }
            }


        }
        else
        {
            // When the left button is released, we release the
            // item.
            mGrabbedItem = nullptr;
        }

        // Force the screen to redraw
        Refresh();
    }
}


