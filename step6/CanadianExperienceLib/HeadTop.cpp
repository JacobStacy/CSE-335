/**
 * @file HeadTop.cpp
 * @author Jacob Stacy
 */

#include "HeadTop.h"

/**
 * Constructor
 * @param name The drawable name
 * @param filename The filename for the image
 */
HeadTop::HeadTop(const std::wstring& name, const std::wstring& filename) :ImageDrawable(name, filename)
{
}


/**
 * Draw the HeadTop
 * @param graphics Graphics context to draw on
 */
void HeadTop::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    ImageDrawable::Draw(graphics);

    wxPoint leftEyebrowPoint = TransformPoint(wxPoint(20, 60));
    wxPoint leftEyebrowPoint2 = TransformPoint(wxPoint(45, 50));
    DrawEyebrow(graphics, leftEyebrowPoint, leftEyebrowPoint2);

    wxPoint rightEyebrowPoint = TransformPoint(wxPoint(65, 50));
    wxPoint rightEyebrowPoint2 = TransformPoint(wxPoint(90, 60));
    DrawEyebrow(graphics, rightEyebrowPoint, rightEyebrowPoint2);

    wxPoint leftEyePoint = TransformPoint(wxPoint(35, 80));
    DrawEye(graphics, leftEyePoint);

    wxPoint rightEyePoint = TransformPoint(wxPoint(75, 80));
    DrawEye(graphics, rightEyePoint);

}

/**
 * Draws an eyebrow
 * @param graphics Graphics context to draw on
 * @param p1 First point for the line
 * @param p2 Second point for the line
 */
void HeadTop::DrawEyebrow(std::shared_ptr<wxGraphicsContext> graphics, wxPoint p1, wxPoint p2)
{
    wxPen eyebrowPen(*wxBLACK, 3);
    graphics->SetPen(eyebrowPen);
    graphics->StrokeLine(p1.x, p1.y, p2.x, p2.y);
}

/**
 * Draws an eye
 * @param graphics Graphics context to draw on
 * @param p1 Point for the eye
 */
void HeadTop::DrawEye(std::shared_ptr<wxGraphicsContext> graphics, wxPoint p1)
{
    float wid = 15.0f;
    float hit = 20.0f;

    graphics->PushState();
    graphics->Translate(p1.x, p1.y);
    graphics->Rotate(-mPlacedR);
    graphics->DrawEllipse(-wid/2, -hit/2, wid, hit);
    graphics->PopState();
}

/** Transform a point from a location on the bitmap to
*  a location on the screen.
* @param  p Point to transform
* @returns Transformed point
*/
wxPoint HeadTop::TransformPoint(wxPoint p)
{
    // Make p relative to the image center
    p = p - GetCenter();

    // Rotate as needed and offset
    return RotatePoint(p, mPlacedR) + mPlacedPosition;
}
