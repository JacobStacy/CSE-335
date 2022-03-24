/**
 * @file GameView.cpp
 * @author John Landers, Kurt LaBlanc
 */

#include "pch.h"
#include "GameView.h"
#include <wx/dcbuffer.h>
#include <wx/graphics.h>
#include "Villain.h"
#include "ids.h"
#include "Platform.h"
#include "Wall.h"

using namespace std;

/// Frame duration in milliseconds
const int FrameDuration = 30;

/// Maximum amount of time to allow for elapsed
const double MaxElapsed = 0.050;

/// Level 0
const wxString Level0 = L"levels/level0.xml";

/// Level 1
const wxString Level1 = L"levels/level1.xml";

/// Level 2
const wxString Level2 = L"levels/level2.xml";

/// Level 3
const wxString Level3 = L"levels/level3.xml";

/**
 * Initialize the GameView class
 * @param parent the parent window for this class
 */
void GameView::Initialize(wxFrame* parent)
{
    Create(parent, wxID_ANY);
    SetBackgroundStyle(wxBG_STYLE_PAINT);
    Bind(wxEVT_PAINT, &GameView::OnPaint, this);

    Bind(wxEVT_TIMER, &GameView::OnTimer, this);
    Bind(wxEVT_KEY_DOWN, &GameView::OnKeyDown, this);
    Bind(wxEVT_KEY_UP, &GameView::OnKeyUp, this);

    parent->Bind(wxEVT_COMMAND_MENU_SELECTED, &GameView::LoadLevelZero, this, IDM_LEVELZERO);
    parent->Bind(wxEVT_COMMAND_MENU_SELECTED, &GameView::LoadLevelOne, this, IDM_LEVELONE);
    parent->Bind(wxEVT_COMMAND_MENU_SELECTED, &GameView::LoadLevelTwo, this, IDM_LEVELTWO);
    parent->Bind(wxEVT_COMMAND_MENU_SELECTED, &GameView::LoadLevelThree, this, IDM_LEVELTHREE);
    mTimer.SetOwner(this);
    mTimer.Start(FrameDuration);
    mStopWatch.Start();


}

/**
 * Paint event that draws the window
 * @param event Paint event object
 */
void GameView::OnPaint(wxPaintEvent& event)
{
    // Compute the time that has elapsed
    // since the last call to OnPaint.
    auto newTime = mStopWatch.Time();
    auto elapsed = (double)(newTime - mTime) * 0.001;
    mTime = newTime;


    ///
    ///Prevent tunneling
    ///
    while (elapsed > MaxElapsed)
    {
        mGame.Update(MaxElapsed);

        elapsed -= MaxElapsed;
    }

    /// Consume remaining time
    if (elapsed > 0)
    {
        mGame.Update(elapsed);
    }

    wxAutoBufferedPaintDC dc(this);

    wxBrush background(*wxWHITE);
    dc.SetBackground(background);
    dc.Clear();

    auto size = GetClientSize();
    auto graphics = wxGraphicsContext::Create(dc);
    mGame.OnDraw(graphics, size.GetWidth(), size.GetHeight());

}

/**
 * Handle a key-down message
 * @param event key event
 */
void GameView::OnKeyDown(wxKeyEvent& event)
{
    mGame.OnKeyDown(event);
}

/**
 * On key up function
 * @param event Event
 */
void GameView::OnKeyUp(wxKeyEvent& event)
{
    mGame.OnKeyUp(event);
}

/**
* Timer event handler
* @param event Timer event
*/
void GameView::OnTimer(wxTimerEvent& event)
{
    Refresh();
}

/**
 * Load level zero event handler
 * @param event Load level button event
 */
void GameView::LoadLevelZero(wxCommandEvent& event)
{
    mGame.SetLevel(Level0);

}

/**
 * Load level one event handler
 * @param event Load level button event
 */
void GameView::LoadLevelOne(wxCommandEvent& event)
{
    mGame.SetLevel(Level1);
}

/**
 * Load level two event handler
 * @param event Load level button event
 */
void GameView::LoadLevelTwo(wxCommandEvent& event)
{
    mGame.SetLevel(Level2);
}

/**
 * Load level three event handler
 * @param event Load level button event
 */
void GameView::LoadLevelThree(wxCommandEvent& event)
{
    mGame.SetLevel(Level3);
    Refresh();
}
