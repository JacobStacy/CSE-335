/**
 * @file TimelineTest.cpp
 * @author Jacob Stacy
 *
 * The test file for the Timeline Class
 *
 */

#include <pch.h>

#include "gtest/gtest.h"
#include <Timeline.h>

using namespace std;

TEST(TimelineTest, Construct)
{
    Timeline timeline;
}

TEST(TimelineTest, GettersSetters)
{

    Timeline timeline;

    ASSERT_EQ(300, timeline.GetNumFrames());
    ASSERT_EQ(30, timeline.GetFrameRate());
    ASSERT_NEAR(0, timeline.GetCurrentTime(), 0.00001);

    timeline.SetNumFrames(1111);
    timeline.SetFrameRate(111);
    timeline.SetCurrentTime(11);

    ASSERT_EQ(1111, timeline.GetNumFrames());
    ASSERT_EQ(111, timeline.GetFrameRate());
    ASSERT_NEAR(11, timeline.GetCurrentTime(), 0.00001);
}

TEST(TimelineTest, GetDuration)
{
    Timeline timeline;

    // Default value
    ASSERT_NEAR(10, timeline.GetDuration(), 0.0001);

    // Changed duration
    timeline.SetFrameRate(375);
    ASSERT_NEAR(300.0 / 375.0, timeline.GetDuration(), 0.0001);

    timeline.SetNumFrames(789);
    ASSERT_NEAR(789.0 / 375.0, timeline.GetDuration(), 0.0001);
}

TEST(TimelineTest, GetCurrentFrame)
{
    Timeline timeline;

    // Default value
    ASSERT_EQ(0, timeline.GetCurrentFrame());

    // Changed time
    timeline.SetCurrentTime(9.27);
    ASSERT_EQ(278, timeline.GetCurrentFrame());
}

