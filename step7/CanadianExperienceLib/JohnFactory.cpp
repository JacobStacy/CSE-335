/**
 * @file JohnFactory.cpp
 * @author Jacob Stacy
 *
 * Implementation of JohnFactory class
 *
 */

#include "pch.h"

#include "JohnFactory.h"
#include "Actor.h"
#include "PolyDrawable.h"
#include "ImageDrawable.h"
#include "HeadTop.h"

using std::shared_ptr;
using std::make_shared;

/**
* This is a factory method that creates our John actor.
* @param imagesDir Directory that contains the images for this application
* @return Pointer to an actor object.
*/
std::shared_ptr<Actor> JohnFactory::Create(std::wstring imagesDir)
{
    shared_ptr<Actor> actor = make_shared<Actor>(L"John");

    auto shirt = make_shared<ImageDrawable>(L"Shirt", imagesDir + L"/john_shirt.png");
    shirt->SetCenter(wxPoint(44, 138));
    shirt->SetPosition(wxPoint(0, -114));
    actor->SetRoot(shirt);


    auto lleg = make_shared<ImageDrawable>(L"Left Leg", imagesDir + L"/john_lleg.png");
    lleg->SetCenter(wxPoint(11, 9));
    lleg->SetPosition(wxPoint(17, 0));
    shirt->AddChild(lleg);

    auto rleg = make_shared<ImageDrawable>(L"Right Leg", imagesDir + L"/john_rleg.png");
    rleg->SetCenter(wxPoint(39, 9));
    rleg->SetPosition(wxPoint(-27, 0));
    shirt->AddChild(rleg);

    auto headb = make_shared<ImageDrawable>(L"Head Bottom", imagesDir + L"/john_headb.png");
    headb->SetCenter(wxPoint(44, 31));
    headb->SetPosition(wxPoint(0, -130));
    shirt->AddChild(headb);

    auto headt = make_shared<HeadTop>(L"Head Top", imagesDir + L"/john_headt_blank.png");
    headt->SetCenter(wxPoint(55, 109));
    headt->SetPosition(wxPoint(5, -20));
    headb->AddChild(headt);

    auto larm = make_shared<PolyDrawable>(L"Left Arm");
    larm->SetColor(wxColour(255, 0, 0));
    larm->SetPosition(wxPoint(45, -130));
    larm->AddPoint(wxPoint(-7, -7));
    larm->AddPoint(wxPoint(-7, 96));
    larm->AddPoint(wxPoint(8, 96));
    larm->AddPoint(wxPoint(8, -7));
    shirt->AddChild(larm);

    auto rarm = make_shared<PolyDrawable>(L"Right Arm");
    rarm->SetColor(wxColour(255, 0, 0));
    rarm->SetPosition(wxPoint(-45, -130));
    rarm->AddPoint(wxPoint(-7, -7));
    rarm->AddPoint(wxPoint(-7, 96));
    rarm->AddPoint(wxPoint(8, 96));
    rarm->AddPoint(wxPoint(8, -7));
    shirt->AddChild(rarm);

    auto lhand = make_shared<PolyDrawable>(L"Left Hand");
    lhand->SetColor(wxColour(253, 218, 180));
    lhand->SetPosition(wxPoint(0, 96));
    lhand->AddPoint(wxPoint(-12, -2));
    lhand->AddPoint(wxPoint(-12, 17));
    lhand->AddPoint(wxPoint(11, 17));
    lhand->AddPoint(wxPoint(11, -2));
    larm->AddChild(lhand);

    auto rhand = make_shared<PolyDrawable>(L"Right Hand");
    rhand->SetColor(wxColour(253, 218, 180));
    rhand->SetPosition(wxPoint(0, 96));
    rhand->AddPoint(wxPoint(-12, -2));
    rhand->AddPoint(wxPoint(-12, 17));
    rhand->AddPoint(wxPoint(11, 17));
    rhand->AddPoint(wxPoint(11, -2));
    rarm->AddChild(rhand);


    actor->AddDrawable(larm);
    actor->AddDrawable(rarm);
    actor->AddDrawable(rhand);
    actor->AddDrawable(lhand);
    actor->AddDrawable(rleg);
    actor->AddDrawable(lleg);
    actor->AddDrawable(shirt);
    actor->AddDrawable(headb);
    actor->AddDrawable(headt);

    return actor;
}