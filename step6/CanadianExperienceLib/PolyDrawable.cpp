/**
 * @file PolyDrawable.cpp
 * @author Jacob Stacy
 */

#include "PolyDrawable.h"

PolyDrawable::PolyDrawable(const std::wstring& name) : Drawable(name)
{

}

void PolyDrawable::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{

}

bool PolyDrawable::HitTest(wxPoint pos)
{
    return false;
}

void PolyDrawable::AddPoint(wxPoint point)
{

}
