/**
 * @file ViewTimeline.cpp
 * @author Charles B. Owen
 * @author Jacob R. Stacy
 */

#include "pch.h"

#include <wx/dcbuffer.h>
#include <wx/xrc/xmlres.h>
#include <sstream>

#include "ViewTimeline.h"
#include "TimelineDlg.h"
#include "Picture.h"
#include "Actor.h"

/// Height to make this window
static const int Height = 90;

/// Y location for the top of a tick mark
const int TickTop = 15;

/// The spacing between ticks in the timeline
const int TickSpacing = 4;

/// The length of a short tick mark
const int TickShort = 10;

/// The length of a long tick mark
const int TickLong = 20;

/// Size of the tick mark labels
const int TickFontSize = 15;

/// Space to the left of the scale
const int BorderLeft = 10;

/// Space to the right of the scale
const int BorderRight = 10;

/// Filename for the pointer image
//const std::wstring PointerImageFile = L"/pointer.png";

/**
 * Constructor
 * @param parent The main wxFrame object
 */
ViewTimeline::ViewTimeline(wxFrame* parent, std::wstring imagesDir) :
    wxScrolledCanvas(parent,
            wxID_ANY,
            wxDefaultPosition,
            wxSize(100, Height),
            wxBORDER_SIMPLE)
{
    SetBackgroundStyle(wxBG_STYLE_PAINT);

    Bind(wxEVT_PAINT, &ViewTimeline::OnPaint, this);
    Bind(wxEVT_LEFT_DOWN, &ViewTimeline::OnLeftDown, this);
    Bind(wxEVT_LEFT_UP, &ViewTimeline::OnLeftUp, this);
    Bind(wxEVT_MOTION, &ViewTimeline::OnMouseMove, this);

    parent->Bind(wxEVT_COMMAND_MENU_SELECTED,
            &ViewTimeline::OnEditTimelineProperties, this,
            XRCID("EditTimelineProperties"));

    parent->Bind(wxEVT_COMMAND_MENU_SELECTED,
            &ViewTimeline::OnSetKeyframe, this,
            XRCID("SetKeyframe"));

    parent->Bind(wxEVT_COMMAND_MENU_SELECTED,
            &ViewTimeline::OnDeleteKeyframe, this,
            XRCID("DeleteKeyframe"));
    

    mPointerImage = std::make_unique<wxImage>(imagesDir + L"/pointer.png", wxBITMAP_TYPE_ANY);


}


/**
 * Paint event, draws the window.
 * @param event Paint event object
 */
void ViewTimeline::OnPaint(wxPaintEvent& event)
{
    auto timeline = GetPicture()->GetTimeline();

    SetVirtualSize(BorderLeft + (timeline->GetNumFrames() * TickSpacing) + BorderRight, 0);
    SetScrollRate(1, 0);

    wxAutoBufferedPaintDC dc(this);
    DoPrepareDC(dc);

    wxBrush background(*wxWHITE);
    dc.SetBackground(background);
    dc.Clear();

    // Create a graphics context
    auto graphics = std::shared_ptr<wxGraphicsContext>(wxGraphicsContext::Create( dc ));

    wxPen pen(wxColour(0, 0, 0), 1);
    graphics->SetPen(pen);

    wxFont font(wxSize(0, TickFontSize),
            wxFONTFAMILY_SWISS,
            wxFONTSTYLE_NORMAL,
            wxFONTWEIGHT_NORMAL);
    graphics->SetFont(font, *wxBLACK);

    for (int tickNum = 0; tickNum <= timeline->GetNumFrames(); tickNum++)
    {
        bool onSecond = (tickNum % timeline->GetFrameRate()) == 0;
        double x = BorderLeft + (TickSpacing * tickNum);

        if (onSecond)
        {
            // Draw Long Tick
            graphics->StrokeLine(x, TickTop, x, TickTop + TickLong);

            // Convert the tick number to seconds in a string
            std::wstringstream str;
            str << tickNum / timeline->GetFrameRate();
            std::wstring wstr = str.str();

            // Get Width of the String
            double numWidth, h;
            graphics->GetTextExtent(wstr, &numWidth, &h);

            graphics->DrawText(wstr, x - (numWidth / 2), TickTop + TickLong + TickSpacing);
        } else
        {
            // Draw Short Tick
            graphics->StrokeLine(x, TickTop, x, TickTop + TickShort);
        }
    }

    if(mPointerBitmap.IsNull())
    {
        mPointerBitmap = graphics->CreateBitmapFromImage(*mPointerImage);
    }

    graphics->DrawBitmap(mPointerBitmap,
            (mPointerImage->GetWidth() / 2) + (TickSpacing * timeline->GetCurrentFrame()), TickTop,
            mPointerImage->GetWidth(),
            mPointerImage->GetHeight());



}

/**
 * Handle the left mouse button down event
 * @param event
 */
void ViewTimeline::OnLeftDown(wxMouseEvent &event)
{
    auto click = CalcUnscrolledPosition(event.GetPosition());

    int x = click.x;

    // Get the timeline
    Timeline *timeline = GetPicture()->GetTimeline();
    int pointerX = (int)(timeline->GetCurrentTime() *
            timeline->GetFrameRate() * TickSpacing + BorderLeft);

    mMovingPointer = x >= pointerX - mPointerImage->GetWidth() / 2 &&
            x <= pointerX + mPointerImage->GetWidth() / 2;


}

/**
* Handle the left mouse button up event
* @param event
*/
void ViewTimeline::OnLeftUp(wxMouseEvent &event)
{
    OnMouseMove(event);
}

/**
* Handle the mouse move event
* @param event
*/
void ViewTimeline::OnMouseMove(wxMouseEvent &event)
{
    auto click = CalcUnscrolledPosition(event.GetPosition());
    int x = click.x;

    // Get the timeline
    Timeline *timeline = GetPicture()->GetTimeline();

    if (event.LeftIsDown())
    {
        if (mMovingPointer)
        {
            double newTime = static_cast<double>(x-BorderLeft) / (timeline->GetFrameRate()*TickSpacing);
            if (newTime >= 0 && newTime <= timeline->GetDuration())
            {
                GetPicture()->SetAnimationTime(newTime);
            }

        }
    }
}

/**
 * Force an update of this window when the picture changes.
 */
void ViewTimeline::UpdateObserver()
{
    Refresh();
}

/**
 * Handle an Edit>Timeline Properties... menu option
 * @param event The menu event
 */
void ViewTimeline::OnEditTimelineProperties(wxCommandEvent& event)
{
    TimelineDlg dlg(this->GetParent(), PictureObserver::GetPicture()->GetTimeline());
    if(dlg.ShowModal() == wxID_OK)
    {
        // The dialog box has changed the Timeline settings
        GetPicture()->UpdateObservers();
    }
}

/**
 * Handle an Edit>Set Keyframe menu option
 * @param event The menu event
 */
void ViewTimeline::OnSetKeyframe(wxCommandEvent& event)
{
    auto picture = GetPicture();
    for (auto actor : *picture)
    {
        actor->SetKeyframe();
    }
}

/**
 * Handle an Edit>Delete Keyframe menu option
 * @param event The menu event
 */
void ViewTimeline::OnDeleteKeyframe(wxCommandEvent& event)
{
    auto timeline = GetPicture()->GetTimeline();

    auto picture = GetPicture();
    for (auto actor : *picture)
    {
        actor->DeleteKeyframe();
    }

    picture->SetAnimationTime(timeline->GetCurrentTime());
}

