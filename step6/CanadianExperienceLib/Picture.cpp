/**
 * @file Picture.cpp
 * @author Jacob Stacy
 *
 * Implementation of Picture class
 *
 */

#include "pch.h"

#include "Picture.h"
#include "PictureObserver.h"
#include "Actor.h"


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
    for (auto actor : mActors)
    {
        actor->Draw(graphics);
    }
}

/**
 * Add's Actor to the list of Actors
 * @param actor Actor tp be Added
 */
void Picture::AddActor(std::shared_ptr<Actor> actor)
{
    actor->SetPicture(this);
    mActors.push_back(actor);
}
