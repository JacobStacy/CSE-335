/**
 * @file HaroldFactory.cpp
 * @author Jacob Stacy
 *
 * Implementation of HaroldFactory class
 *
 */

#include "pch.h"

#include "HaroldFactory.h"
#include "Actor.h"
#include "PolyDrawable.h"

using std::make_shared;

/**
 * This is a factory method that creates our Harold actor.
 * @param imagesDir Directory that contains the images for this application
 * @return Pointer to an actor object.
 */
std::shared_ptr<Actor> HaroldFactory::Create(std::wstring imagesDir)
{
    auto actor = make_shared<Actor>(L"Harold");

    auto poly1 = make_shared<PolyDrawable>(L"Polygon 1");
    poly1->SetColor(wxColour(60, 174, 184));
    poly1->SetPosition(wxPoint(0, -400));
    poly1->SetRotation(0);
    poly1->AddPoint(wxPoint(0, 0));
    poly1->AddPoint(wxPoint(-50, 100));
    poly1->AddPoint(wxPoint(0, 200));
    poly1->AddPoint(wxPoint(50, 100));

    auto poly2 = make_shared<PolyDrawable>(L"Polygon 2");
    poly2->SetColor(wxColour(255, 174, 184));
    poly2->SetPosition(wxPoint(0, 200));
    poly2->SetRotation(0);
    poly2->AddPoint(wxPoint(0, 0));
    poly2->AddPoint(wxPoint(-50, 100));
    poly2->AddPoint(wxPoint(0, 200));
    poly2->AddPoint(wxPoint(50, 100));
    poly1->AddChild(poly2);

    actor->AddDrawable(poly1);
    actor->AddDrawable(poly2);
    actor->SetRoot(poly1);

    return actor;
}