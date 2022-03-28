/**
 * @file PolyDrawableTest.cpp
 * @author Jacob R. Stacy
 * 
 * Test file for PolyDrawable class
 * 
 */

#include <pch.h>

#include <PolyDrawable.h>
#include "gtest/gtest.h"


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

