/**
 * @file PictureFactory.cpp
 * @author Charles Owen
 */

#include "pch.h"
#include "PictureFactory.h"
#include "Picture.h"
#include "HaroldFactory.h"
#include "SpartyFactory.h"
#include "FrankFactory.h"
#include "Actor.h"
#include "ImageDrawable.h"
#include "LaboratoryAdapter.h"

using namespace std;

/// Directory within resources that contains the images.
const std::wstring ImagesDirectory = L"/images";


/**
 * Factory method to create a new picture.
 * @param resourcesDir Directory that contains the images for this application
 * @return The created picture
 */
std::shared_ptr<Picture> PictureFactory::Create(std::wstring resourcesDir)
{
    auto imagesDir = resourcesDir + ImagesDirectory;

    shared_ptr<Picture> picture = make_shared<Picture>();

    shared_ptr<Actor> lab = make_shared<Actor>(L"Lab");
    lab->AddDrawable(make_shared<LaboratoryAdapter>(L"LabAdaptor"));
    picture->AddActor(lab);

    // Create and add Harold
    HaroldFactory haroldFactory;
    auto harold = haroldFactory.Create(imagesDir);

    // This is where Harold will start out.
    harold->SetPosition(wxPoint(750, 785));
    picture->AddActor(harold);

    // Create and add Sparty
    SpartyFactory spartyFactory;
    auto sparty = spartyFactory.Create(imagesDir);

    sparty->SetPosition(wxPoint(1100, 785));
    picture->AddActor(sparty);

    // Create and add Frank
    FrankFactory frankFactory;
    auto frank = frankFactory.Create(imagesDir);

    frank->SetPosition(wxPoint(300, 800));
    picture->AddActor(frank);

    return picture;
}

