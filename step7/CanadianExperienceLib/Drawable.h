/**
 * @file Drawable.h
 * @author Jacob Stacy
 *
 * Abstract base class for drawable elements of our picture.
 *
 */

#ifndef CANADIANEXPERIENCE_DRAWABLE_H
#define CANADIANEXPERIENCE_DRAWABLE_H

#include "AnimChannelAngle.h"
#include "AnimChannelMove.h"

class Actor;
class Timeline;

/**
 * Abstract base class for drawable elements of our picture.
 *
 * A drawable is one part of an actor. Drawable parts can be moved
 * independently.
 */
class Drawable {
private:

    /// Drawable's Name
    std::wstring mName;

    /// Rotation of the Drawable related to it's parent
    double mRotation = 0;

    /// The actor using this drawable
    Actor *mActor = nullptr;
    
    /// The Parent Drawable
    Drawable *mParent = nullptr;
    
    /// The children of the Drawable
    std::vector<std::shared_ptr<Drawable>> mChildren;

    /// The animation channel for animating the angle of this drawable
    AnimChannelAngle mAngleChannel;

protected:

    /// The postion the Drawable is placed
    wxPoint mPlacedPosition = wxPoint(0,0);

    /// The placed rotation of the Drawable
    double mPlacedR = 0;

    Drawable(const std::wstring & name);

    wxPoint RotatePoint(wxPoint point, double angle);

/// Drawable's position related to it's parent
wxPoint mPosition = wxPoint(0, 0);
public:

    /// Default constructor (disabled)
    Drawable() = delete;
    /// Copy Constructor (Disabled)
    Drawable(const Drawable &) = delete;
    /// Assignment Operator (Disabled)
    void operator=(const Drawable &) = delete;

    /// Destructor
    virtual ~Drawable() {}

    void SetActor(Actor *actor);
    void Place(wxPoint offset, double rotate);
    void AddChild(std::shared_ptr<Drawable> child);
    void Move(wxPoint delta);

    /**
     * Draw this drawable
     * @param graphics Graphics object to draw on
     */
    virtual void Draw(std::shared_ptr<wxGraphicsContext> graphics) = 0;

    /**
     * Test to see if we have been clicked on by the mouse
     * @param pos Position to test
     * @return true if clicked on
     */
    virtual bool HitTest(wxPoint pos) = 0;

    /**
     * Get the drawable name
     * @return The drawable name
     */
    std::wstring GetName() const { return mName; }

    /**
     * Is this a movable drawable?
     * @return true if movable
     */
    virtual bool IsMovable() { return false; }

    /**
     * Set the drawable position
     * @param pos The new drawable position
     */
    void SetPosition(wxPoint pos) { mPosition = pos; }

    /**
     * Get the drawable position
     * @return The drawable position
     */
    wxPoint GetPosition() const { return mPosition; }

    /**
     * Set the rotation angle in radians
    * @param r The new rotation angle in radians
     */
    void SetRotation(double r) { mRotation = r; }

    /**
     * Get the rotation angle in radians
     * @return The rotation angle in radians
     */
    double GetRotation() const { return mRotation; }

    /**
     * Set the parent Drawable
    * @param parent The new parent Drawable
     */
    void SetParent(Drawable *parent) { mParent = parent; }

    /**
     * Get the parent for the Drawable
     * @return The parent Drawable
     */
    Drawable* GetParent() const { return mParent; }

    virtual void SetTimeline(Timeline* timeline);

    /**
     * The angle animation channel
     * @return Pointer to animation channel
     */
    AnimChannelAngle *GetAngleChannel() { return &mAngleChannel; }

    /**
     * The move animation channel
     * @return Pointer to animation channel
     */
    virtual AnimChannelMove *GetMoveChannel() {return nullptr;}

    virtual void SetKeyframe();

    virtual void GetKeyframe();
};

#endif //CANADIANEXPERIENCE_DRAWABLE_H
