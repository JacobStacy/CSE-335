/**
 * @file PolyDrawableTest.cpp
 * @author Jacob R. Stacy
 * 
 * Test file for PolyDrawable class
 * 
 */

#include <pch.h>

#include "gtest/gtest.h"
#include <PolyDrawable.h>
#include <Actor.h>


TEST(PolyDrawableTest, Construct)
{
    PolyDrawable polyDrawable(L"Name");
    ASSERT_EQ(polyDrawable.GetName(), std::wstring(L"Name"));
}

TEST(PolyDrawableTest, Color)
{
    PolyDrawable polyDrawable(L"Name");

    // Check Default
    wxColour color = *wxBLACK;
    ASSERT_EQ(polyDrawable.GetColor(), color);

    // Check Setter
    color = *wxBLUE;
    polyDrawable.SetColor(color);
    ASSERT_EQ(polyDrawable.GetColor(), color);
}

TEST(PolyDrawableTest, HitTest)
{
    // Create a bitmap, and a memory device
    // context that draws on that bitmap
    wxBitmap bitmap(1000, 1000);
    wxMemoryDC dc(bitmap);

    // Create a graphics context
    auto graphics = std::shared_ptr<wxGraphicsContext>(wxGraphicsContext::Create( dc ));

    auto actor = std::make_shared<Actor>(L"Square");
    actor->SetPosition(wxPoint(100, 500));

    auto poly1 = std::make_shared<PolyDrawable>(L"Polygon");
    poly1->SetPosition(wxPoint(100, 100));
    poly1->SetRotation(M_PI/2);
    poly1->AddPoint(wxPoint(0, 0));
    poly1->AddPoint(wxPoint(100, 0));
    poly1->AddPoint(wxPoint(100, 100));
    poly1->AddPoint(wxPoint(0, 100));

    actor->AddDrawable(poly1);
    actor->SetRoot(poly1);

    actor->Draw(graphics);

    // Inside the square
    ASSERT_TRUE(poly1->HitTest(wxPoint(210, 590)));

    // To the left
    ASSERT_FALSE(poly1->HitTest(wxPoint(190, 590)));

    // Below
    ASSERT_FALSE(poly1->HitTest(wxPoint(210, 610)));

    // To the right
    ASSERT_FALSE(poly1->HitTest(wxPoint(310, 590)));

    // Above
    ASSERT_FALSE(poly1->HitTest(wxPoint(210, 490)));
}
