/**
 * @file PictureObserverTest.cpp
 * @author Jacob Stacy
 */

#include <pch.h>
#include "gtest/gtest.h"

#include <memory>

#include <Picture.h>
#include <PictureObserver.h>


/**
 * Mock Picture Observer for the PictureObserver Test
 */
class PictureObserverMock : public PictureObserver
{
public:
    bool mUpdated = false;

    PictureObserverMock() : PictureObserver() {}
    virtual void UpdateObserver() override { mUpdated = true; }

};



TEST(PictureObserverTest, Construct)
{
    PictureObserverMock observer;
}

TEST(PictureObserverTest, OneObserver)
{
    // Allocate a Picture object
    auto picture = std::make_shared<Picture>();

    // Create a mock observer object
    PictureObserverMock observer;

    // And set it for the observer:
    observer.SetPicture(picture);

    picture->UpdateObservers();

    ASSERT_TRUE(observer.mUpdated);
}

TEST(PictureObserverTest, GetPicture)
{
    // Allocate a Picture object
    auto picture = std::make_shared<Picture>();

    // Create a mock observer object
    PictureObserverMock observer;

    // And set it for the observer:
    observer.SetPicture(picture);

    picture->UpdateObservers();

    ASSERT_EQ(picture, observer.GetPicture());
}

TEST(PictureObserverTest, TwoObserver)
{
    // Allocate a Picture object
    auto picture = std::make_shared<Picture>();

    // Create a mock observer objects
    PictureObserverMock observer;
    PictureObserverMock observer2;

    // And set it for the observers:
    observer.SetPicture(picture);
    observer2.SetPicture(picture);

    picture->UpdateObservers();

    ASSERT_TRUE(observer.mUpdated);
    ASSERT_TRUE(observer2.mUpdated);
}

TEST(PictureObserverTest, DestructOneofTwoObservers)
{
    // Allocate a Picture object
    auto picture = std::make_shared<Picture>();

    // Create a mock observer object
    PictureObserverMock observer;

    // And set it for the observer:
    observer.SetPicture(picture);

    {
        PictureObserverMock observer2;

        // And set it for the observer:
        observer2.SetPicture(picture);
        picture->UpdateObservers();
    }

    picture->UpdateObservers();

    ASSERT_TRUE(observer.mUpdated);
}



