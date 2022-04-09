/**
 * @file AnimChannel.h
 * @author Jacob R. Stacy
 *
 *
 */

#ifndef CANADIANEXPERIENCE_ANIMCHANNEL_H
#define CANADIANEXPERIENCE_ANIMCHANNEL_H

class Timeline;

/**
 * Base class for animation channels
 *
 * This class provides basic functionality and a polymorphic
 * representation for animation channels.
 */
class AnimChannel {
private:

    /// Name of the AnimChannel
    std::wstring mName;

    /// First Keyframe
    int mKeyframe1 = -1;

    /// Second Keyframe
    int mKeyframe2 = -1;

    /// The timeline object
    Timeline *mTimeline = nullptr;


protected:
    /// Default constructor
    AnimChannel() { }

    /// Class that represents a keyframe
    class Keyframe
    {
    private:

        /// The frame
        int mFrame;

        /// The channel this keyframe is associated with
        AnimChannel *mChannel;

    protected:
        /**
         * Constructor
         * @param channel Channel we are associated with 
         */
        Keyframe(AnimChannel *channel) : mChannel(channel) {}

    public:

        /// Copy constructor (disabled)
        Keyframe(const Keyframe &) = delete;
        /// Assignment operator
        void operator=(const Keyframe &) = delete;

        virtual void UseAs1() = 0;
        virtual void UseAs2() = 0;
        virtual void UseOnly() = 0;

        /**
         * Set Frame
         * @param frame New Frame
         */
        void SetFrame(int frame) { mFrame = frame; }

        /**
         * Get Frame
         * @return Frame
         */
        double GetFrame() { return mFrame;}
    };

    void InsertKeyframe( std::shared_ptr<Keyframe> keyframe);

    virtual void Tween (double t) = 0;

private:
    /// The collection of keyframes for this channel
    std::vector<std::shared_ptr<Keyframe>> mKeyframes;

public:

    virtual ~AnimChannel();
    /// Copy constructor (disabled)
    AnimChannel(const AnimChannel &) = delete;
    /// Assignment operator
    void operator=(const AnimChannel &) = delete;

    /**
     * Set name
     * @param name New Name
     */
    void SetName(std::wstring name) { mName = name; }

    /**
     * Get Name
     * @return Name
     */
    std::wstring GetName() { return mName; }


    bool IsValid();

    void SetFrame(int currFrame);

    void SetTimeline(Timeline* timeline) { mTimeline = timeline; }

    Timeline* GetTimeline() { return mTimeline; }

    void DeleteKeyframe();
};

#endif //CANADIANEXPERIENCE_ANIMCHANNEL_H
