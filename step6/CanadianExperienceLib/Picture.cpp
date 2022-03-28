/**
 * @file Picture.cpp
 * @author Jacob Stacy
 */

#include "pch.h"

#include "Picture.h"
#include "PictureObserver.h"


/**
 * Add an observer to this picture.
 * @param observer The observer to add
 */
void Picture::AddObserver(PictureObserver* observer)
{
    mObservers.push_back(observer);
}

/**
 * Remove an observer from this picture
 * @param observer The observer to remove
 */
void Picture::RemoveObserver(PictureObserver* observer)
{
    auto loc = find(std::begin(mObservers), std::end(mObservers), observer);
    if (loc != std::end(mObservers))
    {
        mObservers.erase(loc);
    }
}

/**
 * Update all observers to indicate the picture has changed.
 */
void Picture::UpdateObservers()
{
    for (auto observer : mObservers)
    {
        observer->UpdateObserver();
    }
}

/**
 * Draw this picture on a device context
 * @param graphics The device context to draw on
 */
void Picture::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    wxPen pen(wxColour(0, 128, 0), 1);
    graphics->SetPen(pen);
    graphics->DrawRectangle(400, 300, 200, 60);

    wxFont font(wxSize(0, 16),
            wxFONTFAMILY_SWISS,
            wxFONTSTYLE_NORMAL,
            wxFONTWEIGHT_NORMAL);
    graphics->SetFont(font, *wxBLACK);
    graphics->DrawText(L"Welcome to Canada!", 410, 310);

    auto time = wxDateTime::Now();
    auto timeStr = time.Format(L"%x %T");
    graphics->DrawText(timeStr, 410, 340);
}