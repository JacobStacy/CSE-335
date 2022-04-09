/**
 * @file AnimChannelAngle.h
 * @author Jacob R. Stacy
 *
 *
 */

#ifndef CANADIANEXPERIENCE_ANIMCHANNELANGLE_H
#define CANADIANEXPERIENCE_ANIMCHANNELANGLE_H

#include "AnimChannel.h"

/**
 * Animation channel for angles.
 */
class AnimChannelAngle : public AnimChannel{
private:

    double mAngle = 0;


protected:
    /// Class that represents a keyframe
    class KeyframeAngle : public Keyframe
    {
    private:

        double mAngle;

        /// The channel this keyframe is associated with
        AnimChannelAngle *mChannel;

    public:

        /**
         * Constructor
         * @param channel The channel we are for
         * @param angle The angle for the keyframe
         */
        KeyframeAngle(AnimChannelAngle *channel, double angle) :
                Keyframe(channel), mChannel(channel), mAngle(angle) {}

        /// Copy constructor (disabled)
        KeyframeAngle(const KeyframeAngle &) = delete;
        /// Assignment operator
        void operator=(const KeyframeAngle &) = delete;

        /// Use this keyframe as keyframe 1
        void UseAs1() override { mChannel->mKeyframe1 = this; }

        /// Use this keyframe as keyfraem 2
        void UseAs2() override { mChannel->mKeyframe2 = this; }

        /// Use this keyframe as the angle
        void UseOnly() override { mChannel->mAngle = mAngle; }

        /**
         * Gets angle
         * @return angle
         */
        double GetAngle() { return mAngle;}
    };

    void Tween(double t) override;

private:

    /// The first angle keyframe
    KeyframeAngle *mKeyframe1 = nullptr;

    /// The second angle keyframe
    KeyframeAngle *mKeyframe2 = nullptr;

public:


    AnimChannelAngle();

    /// Copy Constructor (Disabled)
    AnimChannelAngle(const AnimChannelAngle &) = delete;
    /// Assignment Operator (Disabled)
    void operator=(const AnimChannelAngle &) = delete;

    ~AnimChannelAngle() override;

    void SetKeyframe(double angle);

    double GetAngle() { return mAngle; }

};

#endif //CANADIANEXPERIENCE_ANIMCHANNELANGLE_H
