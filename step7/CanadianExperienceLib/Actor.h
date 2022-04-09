/**
 * @file Actor.h
 * @author Jacob Stacy
 *
 * Class for actors in our drawings.
 */

#ifndef CANADIANEXPERIENCE_ACTOR_H
#define CANADIANEXPERIENCE_ACTOR_H

#include "AnimChannelMove.h"

class Drawable;
class Picture;

/**
 * Class for actors in our drawings.
 *
 * An actor is some graphical object that consists of
 * one or more parts. Actors can be animated.
 */
class Actor {
private:

    /// Name of the Actor
    std::wstring mName;

    /// Whether the Actor is enabled or not
    bool mEnabled = true;

    /// Actor's position
    wxPoint mPosition = wxPoint(0,0);

    /// Whether the Actor is clickable or not
    bool mClickable = true;

    /// The root drawable
    std::shared_ptr<Drawable> mRoot;

    /// The drawables in drawing order
    std::vector<std::shared_ptr<Drawable>> mDrawablesInOrder;

    /// The Picture the actor is part of
    Picture *mPicture = nullptr;

    /// The animation channel for animating the move of this drawable
    AnimChannelMove mMoveChannel;

public:

    /// Destructor
    virtual ~Actor() {}

    Actor(const std::wstring & name);

    /// Default constructor (disabled)
    Actor() = delete;
    /// Copy Constructor (Disabled)
    Actor(const Actor &) = delete;
    /// Assignment Operator (Disabled)
    void operator=(const Actor &) = delete;

    void SetRoot (std::shared_ptr<Drawable> root);
    void Draw(std::shared_ptr<wxGraphicsContext> graphics);
    std::shared_ptr<Drawable> HitTest(wxPoint pos);
    void AddDrawable(std::shared_ptr<Drawable> drawable);

    /**
     * Get the actor name
     * @return Actor name
     */
    std::wstring GetName() const { return mName; }

    /**
     * Actor is enabled
     * @return enabled status
     */
    bool IsEnabled() const { return mEnabled; }

    /**
     * Set Actor enabled
     * @param enabled New enabled status
     */
    void SetEnabled(bool enabled) { mEnabled = enabled; }

    /**
     * Gets the position of the Actor
     * @return The Actor's position
     */
    wxPoint GetPosition() const { return mPosition; }

    /**
     * Set the Actor's position
     * @param pos New position
     */
    void SetPosition(wxPoint pos) { mPosition = pos; }

    /**
     * Actor is clickable
     * @return clickable status
     */
    bool IsClickable() const { return mClickable; }

    /**
     * Set Actor clickable
     * @param clickable New clickable status
     */
    void SetClickable(bool clickable) { mClickable = clickable; }

    /**
     * Set the Picture for the Actor
     * @param picture New Picture
     */
    void SetPicture(Picture *picture);

    /**
     * Get Picture for the Actor
     * @return Actor's Picture
     */
    Picture* GetPicture() { return mPicture; }

    void GetKeyframe();

    void SetKeyframe();

    /**
     * The Move animation channel
     * @return Pointer to animation channel
     */
    AnimChannelMove *GetMoveChannel() { return &mMoveChannel; }

    void DeleteKeyframe();
};

#endif //CANADIANEXPERIENCE_ACTOR_H
