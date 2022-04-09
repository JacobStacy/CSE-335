/**
 * @file AnimChannelAngleTest.cpp
 * @author Jacob Stacy
 *
 * The test file for the AnimChannelAngle Class
 *
 */

#include <pch.h>

#include "gtest/gtest.h"
#include <AnimChannelAngle.h>
#include <Timeline.h>

using namespace std;

/**
 * Mock AnimChannelAngle for the AnimChannelAngle Test
 */
class AnimChannelAngleMock : public AnimChannelAngle {
public:
    AnimChannelAngleMock() : AnimChannelAngle()
    {
    }

    void Tween (double t) override {}

};

TEST(AnimChannelAngleTest, Construct)
{
    AnimChannelAngleMock animChannelAngle;
}

TEST(AnimChannelAngleTest, Name)
{

    AnimChannelAngleMock animChannelAngle;

    animChannelAngle.SetName(L"Name");
    ASSERT_EQ(L"Name", animChannelAngle.GetName());
}

TEST(TimelineTest, Add)
{
    Timeline timeline;
    AnimChannelAngle channel;

    timeline.AddChannel(&channel);
    ASSERT_EQ(&timeline, channel.GetTimeline());
}
