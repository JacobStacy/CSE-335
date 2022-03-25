/**
 * @file PictureTest.cpp
 * @author Jacob Stacy
 *
 * The test file for the Picture Class
 *
 */

#include <pch.h>
#include <Picture.h>
#include "gtest/gtest.h"


TEST(PictureTest, Construct) {
    Picture picture;
}

TEST(PictureTest, Size) {

    Picture picture;

    ASSERT_EQ(800, picture.GetSize().GetHeight());
    ASSERT_EQ(1500, picture.GetSize().GetWidth());


    wxSize size(123, 456);
    picture.SetSize(wxSize(123, 456));

    ASSERT_EQ(size, picture.GetSize());
    ASSERT_EQ(size.GetHeight(), picture.GetSize().GetHeight());
    ASSERT_EQ(size.GetWidth(), picture.GetSize().GetWidth());
}