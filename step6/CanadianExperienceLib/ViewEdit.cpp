/**
 * @file ViewEdit.cpp
 * @author Charles B. Owen
 * @author Jacob R. Stacy
 */

#include "pch.h"

#include <wx/dcbuffer.h>

#include "ViewEdit.h"
#include "Picture.h"

using namespace std;


/**
 * Constructor
 * @param parent Pointer to wxFrame object, the main frame for the application
 */
ViewEdit::ViewEdit(wxFrame* parent) : wxScrolledCanvas(parent, wxID_ANY)
{
    SetBackgroundStyle(wxBG_STYLE_PAINT);

    Bind(wxEVT_PAINT, &ViewEdit::OnPaint, this);
    Bind(wxEVT_LEFT_DOWN, &ViewEdit::OnLeftDown, this);
    Bind(wxEVT_LEFT_UP, &ViewEdit::OnLeftUp, this);
    Bind(wxEVT_MOTION, &ViewEdit::OnMouseMove, this);
}




/**
 * Paint event, draws the window.
 * @param event Paint event object
 */
void ViewEdit::OnPaint(wxPaintEvent& event)
{
    auto size = GetPicture()->GetSize();
    SetVirtualSize(size.GetWidth(), size.GetHeight());
    SetScrollRate(1, 1);

    wxAutoBufferedPaintDC dc(this);
    DoPrepareDC(dc);

    wxBrush background(*wxWHITE);
    dc.SetBackground(background);
    dc.Clear();

    // Create a graphics context
    auto graphics = std::shared_ptr<wxGraphicsContext>(wxGraphicsContext::Create( dc ));

    // Additional drawing code here
    GetPicture()->Draw(graphics);
}



/**
 * Handle the left mouse button down event
 * @param event
 */
void ViewEdit::OnLeftDown(wxMouseEvent &event)
{
    mLastMouse = CalcUnscrolledPosition(event.GetPosition());
    GetPicture()->UpdateObservers();
}

/**
* Handle the left mouse button up event
* @param event
*/
void ViewEdit::OnLeftUp(wxMouseEvent &event)
{
    OnMouseMove(event);
}

/**
* Handle the mouse move event
* @param event
*/
void ViewEdit::OnMouseMove(wxMouseEvent &event)
{
}

/**
 * Force an update of this window when the picture changes.
 */
void ViewEdit::UpdateObserver()
{
    Refresh();
}

