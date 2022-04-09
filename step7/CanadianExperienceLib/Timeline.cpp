/**
 * @file Timeline.cpp
 * @author Jacob Stacy
 */

#include "pch.h"

#include "Timeline.h"
#include "AnimChannel.h"

void Timeline::AddChannel(AnimChannel* channel)
{
    channel->SetTimeline(this);
    mChannels.push_back(channel);
}

/**
 * Sets the current time
 *
 * Ensures all of the channels are
 * valid for that point in time.
 * @param t The new time to set
 */
void Timeline::SetCurrentTime(double t)
{
    // Set the time
    mCurrentTime = t;

    for (auto channel : mChannels)
    {
        channel->SetFrame(GetCurrentFrame());
    }
}
