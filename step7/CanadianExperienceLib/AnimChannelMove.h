/**
 * @file AnimChannelMove.h
 * @author Jacob R. Stacy
 *
 *
 */

#ifndef CANADIANEXPERIENCE_ANIMCHANNELMOVE_H
#define CANADIANEXPERIENCE_ANIMCHANNELMOVE_H

#include "AnimChannel.h"

/**
 * Animation channel for moves.
 */
class AnimChannelMove : public AnimChannel{
private:

    wxPoint mMove = wxPoint(0, 0);


protected:
    /// Class that represents a keyframe
    class KeyframeMove : public Keyframe
    {
    private:

        wxPoint mMove;

        /// The channel this keyframe is associated with
        AnimChannelMove *mChannel;

    public:

        /**
         * Constructor
         * @param channel The channel we are for
         * @param move The move for the keyframe
         */
        KeyframeMove(AnimChannelMove *channel, wxPoint move) :
                Keyframe(channel), mChannel(channel), mMove(move) {}

        /// Copy constructor (disabled)
        KeyframeMove(const KeyframeMove &) = delete;
        /// Assignment operator
        void operator=(const KeyframeMove &) = delete;

        /// Use this keyframe as keyframe 1
        void UseAs1() override { mChannel->mKeyframe1 = this; }

        /// Use this keyframe as keyfraem 2
        void UseAs2() override { mChannel->mKeyframe2 = this; }

        /// Use this keyframe as the move
        void UseOnly() override { mChannel->mMove = mMove; }

        /**
         * Gets move
         * @return move
         */
        wxPoint GetMove() { return mMove;}
    };

    void Tween(double t) override;

private:

    /// The first move keyframe
    KeyframeMove *mKeyframe1 = nullptr;

    /// The second move keyframe
    KeyframeMove *mKeyframe2 = nullptr;

public:


    AnimChannelMove();

    /// Copy Constructor (Disabled)
    AnimChannelMove(const AnimChannelMove &) = delete;
    /// Assignment Operator (Disabled)
    void operator=(const AnimChannelMove &) = delete;

    ~AnimChannelMove() override;

    void SetKeyframe(wxPoint move);

    wxPoint GetMove() { return mMove; }

};

#endif //CANADIANEXPERIENCE_ANIMCHANNELMOVE_H
