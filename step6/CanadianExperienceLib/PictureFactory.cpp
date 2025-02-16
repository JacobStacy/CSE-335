/**
 * @file PictureFactory.cpp
 * @author Jacob Stacy
 *
 * Implementation of PictureFactory class
 *
 */

#include "pch.h"

#include "PictureFactory.h"
#include "Picture.h"
#include "HaroldFactory.h"
#include "Actor.h"
#include "ImageDrawable.h"
#include "JohnFactory.h"

using namespace std;

/**
 * Factory method to create a new picture.
 * @param imagesDir Directory that contains the images for this application
 * @return The created picture
 */
std::shared_ptr<Picture> PictureFactory::Create(std::wstring imagesDir)
{
    shared_ptr<Picture> picture = make_shared<Picture>();

    // Create the background and add it
    auto background = make_shared<Actor>(L"Background");
    background->SetClickable(false);
    background->SetPosition(wxPoint(0, 0));
    auto backgroundI =
            make_shared<ImageDrawable>(L"Background", imagesDir + L"/Background.jpg");
    background->AddDrawable(backgroundI);
    background->SetRoot(backgroundI);
    picture->AddActor(background);

    // Create and add Harold
    HaroldFactory haroldFactory;
    auto harold = haroldFactory.Create(imagesDir);

    // Create and add John
    JohnFactory johnFactory;
    auto john = johnFactory.Create(imagesDir);

    // This is where Harold will start out.
    harold->SetPosition(wxPoint(300, 500));
    picture->AddActor(harold);

    // This is where John will start out.
    john->SetPosition(wxPoint(600, 500));
    picture->AddActor(john);

    return picture;
}