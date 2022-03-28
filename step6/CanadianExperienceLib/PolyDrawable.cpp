/**
 * @file PolyDrawable.cpp
 * @author Jacob Stacy
 */

#include "PolyDrawable.h"

PolyDrawable::PolyDrawable(const std::wstring& name) : Drawable(name)
{

}

/**
 * Draw our polygon.
 * @param  graphics The graphics context to draw on
 */
void PolyDrawable::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    if(!mPoints.empty()) {

        mPath = graphics->CreatePath();
        mPath.MoveToPoint(RotatePoint(mPoints[0], mPlacedR) + mPlacedPosition);
        for (auto i = 1; i<mPoints.size(); i++)
        {
            mPath.AddLineToPoint(RotatePoint(mPoints[i], mPlacedR) + mPlacedPosition);
        }
        mPath.CloseSubpath();

        wxBrush brush(mColor);
        graphics->SetBrush(brush);
        graphics->FillPath(mPath);
    }
}

/**
 * Test to see if we hit this object with a mouse click
 * @param pos Click position
 * @return true it hit
 */
bool PolyDrawable::HitTest(wxPoint pos)
{
    return mPath.Contains(pos.x, pos.y);
}

void PolyDrawable::AddPoint(wxPoint point)
{
    mPoints.push_back(point);
}
