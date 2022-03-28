/**
 * @file Actor.cpp
 * @author Jacob Stacy
 */

#include "pch.h"

#include "Actor.h"
#include "Drawable.h"

/**
* Constructor
* @param name The actor name
*/
Actor::Actor(const std::wstring & name) : mName(name)
{

}

/**
 * Set the root drawable for the actor
 * @param root Pointer to root drawable
 */
void Actor::SetRoot(std::shared_ptr<Drawable> root)
{

}

/**
 * Draw this actor
 * @param graphics The Graphics object we are drawing on
 */
void Actor::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{

}

/**
* Test to see if a mouse click is on this actor.
* @param pos Mouse position on drawing
* @return A drawable object we clicked on or nullptr if we missed.
*/
std::shared_ptr<Drawable> Actor::HitTest(wxPoint pos)
{
    return nullptr;
}

/**
* Add a drawable to this actor
* @param drawable The drawable to add
*/
void Actor::AddDrawable(std::shared_ptr<Drawable> drawable)
{

}
