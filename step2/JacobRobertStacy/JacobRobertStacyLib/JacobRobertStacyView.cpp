/**
 * @file JacobRobertStacyView.cpp
 * @author Jacob Stacy
 */

#include "pch.h"
#include "JacobRobertStacyView.h"

#include <wx/dcbuffer.h>

/**
 * Initialize the jacobrobertstacy view class.
 * @param parent The parent window for this class
 */
void JacobRobertStacyView::Initialize(wxFrame* parent)
{
    Create(parent, wxID_ANY);
    SetBackgroundColour(*wxWHITE);
    Bind(wxEVT_PAINT, &JacobRobertStacyView::OnPaint, this);
    SetBackgroundStyle(wxBG_STYLE_PAINT);

}

/**
 * Paint event, draws the window.
 * @param event Paint event object
 */
void JacobRobertStacyView::OnPaint(wxPaintEvent& event)
{
    wxAutoBufferedPaintDC dc(this);

    wxBrush background(*wxWHITE);
    dc.SetBackground(background);
    dc.Clear();


    int viewWidth = dc.GetSize().x;
    int viewHeight = dc.GetSize().y;


    /// Water
    for (int y = 0; y < viewHeight; y++)
    {

        if (y > viewHeight * .53){
            wxPen pen(wxColour(12,  32, 50));
            dc.SetPen(pen);
            dc.DrawLine(0, y, viewWidth, y);
        }

    }



    /// Water Light
    for (int y = 0; y < viewHeight - 100 && y > viewHeight - 565; y++)
    {
        int red = 12 + y;
        int green = 32 + y;
        int blue = 50 + y;




        wxPen pen3(wxColour(red, green, blue));
        dc.SetPen(pen3);
        wxBrush brush(wxColour(red, green, blue));
        dc.SetBrush(brush);
        dc.DrawEllipse((125) + (y) / 2, (viewHeight) - (y * 4), (viewWidth - 250) - (y), 10 * (y + 1) * .5);

    }

    /// Right Water Block
    for (int y = 0; y < viewHeight; y++)
    {

        if (y > viewHeight * .53){
            wxPen pen(wxColour(12,  32, 50));
            dc.SetPen(pen);
            dc.DrawLine(489 - (y *y * .000075), y, viewWidth, y);
        }

    }

    /// Left Water Block
    for (int y = 0; y < viewHeight; y++)
    {

        if (y > viewHeight * .53){
            wxPen pen(wxColour(12,  32, 50));
            dc.SetPen(pen);
            dc.DrawLine(0, y, (viewWidth - 489) + (y *y * .000075), y);
        }

    }







    /// Sky
    for (int y = 0; y < viewHeight; y++)
    {
        if (y < viewHeight * .53)
        {
            wxPen pen(wxColour(11 + (y * .09),  17 + (y * .193), 33 + (y * .196)));
            dc.SetPen(pen);
            dc.DrawLine(0, y, viewWidth, y);
        }
    }

    /// Moon
    wxPen pen2(wxColour(255, 255 , 255, 255));
    wxBrush brush2(wxColour(255, 255 , 255, 255));
    dc.SetBrush(brush2);
    dc.SetPen(pen2);
    dc.DrawCircle(viewWidth / 2, viewHeight * .35 , viewHeight / 6);

    dc.DrawRectangle(100, 25, 3, 3);
    dc.DrawRectangle(150, 50, 3, 3);
    dc.DrawRectangle(50, 75, 3, 3);
    dc.DrawRectangle(600, 25, 3, 3);
    dc.DrawRectangle(650, 50, 3, 3);
    dc.DrawRectangle(750, 20, 3, 3);
    dc.DrawRectangle(550, 10, 3, 3);
    dc.DrawRectangle(400, 25, 3, 3);
    dc.DrawRectangle(350, 50, 3, 3);
    dc.DrawRectangle(600, 75, 3, 3);

    dc.DrawRectangle(100, 125, 3, 3);
    dc.DrawRectangle(150, 150, 3, 3);
    dc.DrawRectangle(50, 175, 3, 3);
    dc.DrawRectangle(600, 125, 3, 3);
    dc.DrawRectangle(650, 150, 3, 3);
    dc.DrawRectangle(750, 120, 3, 3);
    dc.DrawRectangle(550, 110, 3, 3);
    dc.DrawRectangle(400, 125, 3, 3);
    dc.DrawRectangle(350, 150, 3, 3);
    dc.DrawRectangle(600, 175, 3, 3);

    dc.DrawRectangle(100, 225, 3, 3);
    dc.DrawRectangle(150, 250, 3, 3);
    dc.DrawRectangle(50, 275, 3, 3);
    dc.DrawRectangle(600, 225, 3, 3);
    dc.DrawRectangle(650, 250, 3, 3);
    dc.DrawRectangle(750, 220, 3, 3);
    dc.DrawRectangle(550, 210, 3, 3);
    dc.DrawRectangle(400, 225, 3, 3);
    dc.DrawRectangle(350, 250, 3, 3);
    dc.DrawRectangle(600, 275, 3, 3);

    dc.DrawRectangle(200, 125, 3, 3);
    dc.DrawRectangle(250, 150, 3, 3);
    dc.DrawRectangle(150, 175, 3, 3);
    dc.DrawRectangle(400, 125, 3, 3);
    dc.DrawRectangle(450, 150, 3, 3);
    dc.DrawRectangle(650, 120, 3, 3);
    dc.DrawRectangle(450, 110, 3, 3);
    dc.DrawRectangle(600, 125, 3, 3);
    dc.DrawRectangle(350, 150, 3, 3);

    wxBrush unfilled(wxColour(0, 0 , 0, 0));
    dc.SetBrush(unfilled);
    dc.DrawRectangle(600, 275, 3, 3);





}

