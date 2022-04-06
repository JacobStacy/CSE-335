/**
 * @file ActorTest.cpp
 * @author Jacob Stacy
 *
 * The test file for the Actor Class
 *
 */

#include <pch.h>

#include <Actor.h>
#include "gtest/gtest.h"



TEST(ActorTest, Construct)
{
    Actor actor(L"Name");

    ASSERT_EQ(actor.GetName(), std::wstring(L"Name"));
}

TEST(ActorTest, Enabled)
{
    Actor actor(L"Name");

    //Check default
    ASSERT_TRUE(actor.IsEnabled());

    //Check setter false
    actor.SetEnabled(false);
    ASSERT_FALSE(actor.IsEnabled());

    //Check setter true
    actor.SetEnabled(true);
    ASSERT_TRUE(actor.IsEnabled());
}

TEST(ActorTest, Clickable)
{
    Actor actor(L"Name");

    //Check default
    ASSERT_TRUE(actor.IsClickable());

    //Check setter false
    actor.SetClickable(false);
    ASSERT_FALSE(actor.IsClickable());

    //Check setter true
    actor.SetClickable(true);
    ASSERT_TRUE(actor.IsClickable());
}

TEST(ActorTest, Position)
{
    Actor actor(L"Name");
    wxPoint point = wxPoint(0,0);

    //Check default
    ASSERT_EQ(actor.GetPosition(), point);

    //Check setter
    point = wxPoint(100,100);
    actor.SetPosition(point);
    ASSERT_EQ(actor.GetPosition(), point);
}
