/**
 * @file DrawableTest.cpp
 * @author Jacob Stacy
 * 
 * Test file for Drawable class
 * 
 */

#include <pch.h>

#include <Drawable.h>
#include "gtest/gtest.h"

/**
 * Mock Drawable for the Drawable Test
 */
class DrawableMock : public Drawable {
public:
    DrawableMock(const std::wstring &name) : Drawable(name)
    {
    }

    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override {}

    bool HitTest(wxPoint pos) override { return false; }

};


TEST(DrawableTest, Construct)
{
    DrawableMock drawable(L"Name");
    ASSERT_EQ(drawable.GetName(), std::wstring(L"Name"));
}

TEST(DrawableTest, Position)
{
    DrawableMock drawable(L"Name");
    wxPoint point = wxPoint(0,0);

    //Check default
    ASSERT_EQ(drawable.GetPosition(), point);

    //Check setter
    point = wxPoint(100,100);
    drawable.SetPosition(point);
    ASSERT_EQ(drawable.GetPosition(), point);
}

TEST(DrawableTest, Rotation)
{
    DrawableMock drawable(L"Name");
    double rot = 0;

    //Check default
    ASSERT_NEAR(drawable.GetRotation(), rot, 0.00001);

    //Check setter
    rot = 1.2;
    drawable.SetRotation(rot);
    ASSERT_NEAR(drawable.GetRotation(), rot, 0.00001);
}

TEST(DrawableTest, Association)
{
    DrawableMock body(L"Body");
    auto arm = std::make_shared<DrawableMock>(L"Arm");
    auto leg = std::make_shared<DrawableMock>(L"Leg");

    ASSERT_EQ(nullptr, arm->GetParent());
    ASSERT_EQ(nullptr, leg->GetParent());

    body.AddChild(arm);
    body.AddChild(leg);

    ASSERT_EQ(&body, arm->GetParent());
    ASSERT_EQ(&body, leg->GetParent());
}