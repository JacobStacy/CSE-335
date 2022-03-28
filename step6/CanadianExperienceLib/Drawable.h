/**
 * @file Drawable.h
 * @author Jacob Stacy
 *
 * Abstract base class for drawable elements of our picture.
 *
 */

#ifndef CANADIANEXPERIENCE_DRAWABLE_H
#define CANADIANEXPERIENCE_DRAWABLE_H

class Actor;

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

    /// Drawable's position related to it's parent
    wxPoint mPosition = wxPoint(0, 0);

    /// Rotation of the Drawable related to it's parent
    double mRotation = 0;

protected:

    /// The postion the Drawable is placed
    wxPoint mPlacedPosition = wxPoint(0,0);

    /// The placed rotation of the Drawable
    double mPlacedR = 0;

    Drawable(const std::wstring & name);

    wxPoint RotatePoint(wxPoint point, double angle);

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
    bool IsMoveable() { return false; }

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

};

#endif //CANADIANEXPERIENCE_DRAWABLE_H
