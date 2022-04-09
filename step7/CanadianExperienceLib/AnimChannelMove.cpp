/**
 * @file AnimChannelMove.cpp
 * @author Jacob R. Stacy
 */

#include "pch.h"

#include "AnimChannelMove.h"

/**
 * Constructor
 */
AnimChannelMove::AnimChannelMove()
{

}

/**
 * Destructor
 */
AnimChannelMove::~AnimChannelMove()
{

}

/**
 * Compute an move that is an interpolation
 * between two keyframes
 *
 * This function is called after Use1 and Use2,
 * so we have pointers to valid keyframes of the
 * type KeyframeMove. This function computes the
 * tweening.
 *
 * @param t A t value. t=0 means keyframe1, t=1 means keyframe2.
 * Other values interpolate between.
 */
void AnimChannelMove::Tween(double t)
{
    auto a = mKeyframe1->GetMove();
    auto b = mKeyframe2->GetMove();

    mMove = wxPoint(int(a.x + t * (b.x - a.x)),
            int(a.y + t * (b.y - a.y)));
}


/**
 * Set a keyframe
 *
 * This function allocates a new keyframe and sends it to
 * AnimChannel, which will insert it into the collection of keyframes.
 * @param move Move for the keyframe.
 */
void AnimChannelMove::SetKeyframe(wxPoint move)
{
    // Create a keyframe of the appropriate type
    // Telling it this channel and the move
    auto keyframe = std::make_shared<KeyframeMove>(this, move);

    // Insert it into the collection
    InsertKeyframe(keyframe);
}

