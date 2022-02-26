/**
 * @file GameView.cpp
 * @author John Landers
 */

#include "../pch.h"
#include "GameView.h"
#include <wx/dcbuffer.h>
#include <wx/graphics.h>

/**
 * Initialize the GameView class
 * @param parent the parent window for this class
 */
void GameView::Initialize(wxFrame* parent)
{
    Create(parent, wxID_ANY);
    SetBackgroundStyle(wxBG_STYLE_PAINT);
    Bind(wxEVT_PAINT, &GameView::OnPaint, this);
}

/**
 * Paint event that draws the window
 * @param event Paint event object
 */
void GameView::OnPaint(wxPaintEvent& event)
{
    wxAutoBufferedPaintDC dc(this);

    wxBrush background(*wxWHITE);
    dc.SetBackground(background);
    dc.Clear();

    auto size = GetClientSize();
    auto graphics = std::shared_ptr<wxGraphicsContext>(wxGraphicsContext::Create(dc));
    // Uncomment this line when Game class is implemented
    //mGame.OnDraw(graphics, size.GetWidth(), size.GetHeight());
}