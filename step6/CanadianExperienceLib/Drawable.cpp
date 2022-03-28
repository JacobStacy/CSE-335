/**
 * @file Drawable.cpp
 * @author Jacob Stacy
 */

#include "pch.h"

#include "Drawable.h"
#include "Actor.h"


/**
 * Constructor
 * @param name The drawable name
 */
Drawable::Drawable(const std::wstring& name) : mName(name)
{

}

/**
 * Set the actor using this drawable
 * @param actor Actor using this drawable
 */
void Drawable::SetActor(Actor *actor)
{
    mActor = actor;
}

/**
 * Place this drawable relative to its parent
 *
 * This works hierarchically from top item down.
 * @param offset Parent offset
 * @param rotate Parent rotation
 */
void Drawable::Place(wxPoint offset, double rotate)
{

}

/**
 * Add a child drawable to this drawable
 * @param child The child to add
 */
void Drawable::AddChild(std::shared_ptr<Drawable> child)
{

}

/**
 * Move this drawable some amount
 * @param delta The amount to move
 */
void Drawable::Move(wxPoint delta)
{

}

/**
 * Rotate a point by a given angle.
 * @param point The point to rotate
 * @param angle An angle in radians
 * @return Rotated point
 */
wxPoint Drawable::RotatePoint(wxPoint point, double angle)
{
    return wxPoint(0, 0);
}
