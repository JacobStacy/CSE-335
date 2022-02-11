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
#include "DecorCastle.h"

#include <wx/dcbuffer.h>

using namespace std;

/// Frame duration in milliseconds
const int FrameDuration = 30;


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
    mStopWatch.Start();

    parent->Bind(wxEVT_COMMAND_MENU_SELECTED, &AquariumView::OnAddFishBetaFish, this, IDM_ADDFISHBETA);
    parent->Bind(wxEVT_COMMAND_MENU_SELECTED, &AquariumView::OnAddFishNemoFish, this, IDM_ADDFISHNEMO);
    parent->Bind(wxEVT_COMMAND_MENU_SELECTED, &AquariumView::OnAddFishCarpFish, this, IDM_ADDFISHCARP);
    parent->Bind(wxEVT_COMMAND_MENU_SELECTED, &AquariumView::OnAddDecorCastleDecor, this, IDM_ADDDECORCASTLE);
    parent->Bind(wxEVT_COMMAND_MENU_SELECTED, &AquariumView::OnFileSaveAs, this, wxID_SAVEAS);
    parent->Bind(wxEVT_COMMAND_MENU_SELECTED, &AquariumView::OnFileOpen, this, wxID_OPEN);

    Bind(wxEVT_LEFT_DOWN, &AquariumView::OnLeftDown, this);
    Bind(wxEVT_LEFT_UP, &AquariumView::OnLeftUp, this);
    Bind(wxEVT_MOTION, &AquariumView::OnMouseMove, this);
    Bind(wxEVT_TIMER, &AquariumView::OnTimer, this);

    mTimer.SetOwner(this);
    mTimer.Start(FrameDuration);
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

    // Compute the time that has elapsed
    // since the last call to OnPaint.
    auto newTime = mStopWatch.Time();
    auto elapsed = (double)(newTime - mTime) * 0.001;
    mTime = newTime;

    mAquarium.Update(elapsed);

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
 * Menu handier for Add Fish>Carp Fish
 * @param event Mouse event
 */
void AquariumView::OnAddDecorCastleDecor(wxCommandEvent& event)
{
    auto decor = make_shared<DecorCastle>(&mAquarium);
    mAquarium.Add(decor);
    Refresh();
}

/**
 * Menu handler for Save As
 * @param event Mouse event
 */
void AquariumView::OnFileSaveAs(wxCommandEvent& event)
{
    wxFileDialog saveFileDialog(this, _("Save Aquarium file"), "", "",
            "Aquarium Files (*.aqua)|*.aqua", wxFD_SAVE|wxFD_OVERWRITE_PROMPT);
    if (saveFileDialog.ShowModal() == wxID_CANCEL)
    {
        return;
    }

    auto filename = saveFileDialog.GetPath();

    mAquarium.Save(filename);
}

/**
 * File>Open menu handler
 * @param event Menu event
 */
void AquariumView::OnFileOpen(wxCommandEvent& event)
{
    wxFileDialog loadFileDialog(this, _("Load Aquarium file"), "", "",
            "Aquarium Files (*.aqua)|*.aqua", wxFD_OPEN);
    if (loadFileDialog.ShowModal() == wxID_CANCEL)
    {
        return;
    }

    auto filename = loadFileDialog.GetPath();

    mAquarium.Load(filename);
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

/**
 * Handle the left mouse button down event
 * @param event
 */
void AquariumView::OnTimer(wxTimerEvent &event)
{
    Refresh();
}


