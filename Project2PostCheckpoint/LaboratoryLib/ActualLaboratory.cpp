/**
 * @file ActualLaboratory.cpp
 * @author Jacob Stacy
 */

#include "pch.h"

#include <memory>

#include "ActualLaboratory.h"
#include "Component.h"
#include "Event.h"

/**
 * Constructor
 */
ActualLaboratory::ActualLaboratory()
{

}

/**
 * Draws the laboratory
 * @param graphics
 */
void ActualLaboratory::DrawLaboratory(std::shared_ptr<wxGraphicsContext> graphics)
{
    for (auto component : mComponents)
    {
        component->Draw(graphics);
    }
}

/**
 * Loads animation script
 * @param script
 */
void ActualLaboratory::LoadScript(const std::wstring& script)
{
    wxXmlDocument xmlDoc;
    if(!xmlDoc.Load(script))
    {
        wxMessageBox(L"Unable to load Game file");
        return;
    }

    // Get the XML document root node
    auto root = xmlDoc.GetRoot();


    // Get children nodes
    auto child = root->GetChildren();

//    auto child = children->GetChildren();

    while (child != nullptr)
    {
        if (child->GetName() == L"event")
        {
            mEvents.push_back(std::make_shared<Event>(child));
        }

        child = child->GetNext();
    }
}

/**
 * Handles changes in the lab over time
 * @param elapsed
 */
void ActualLaboratory::Update(double elapsed)
{
    if (elapsed > 0)
    {
        //
        // Send any events that become active to the components
        //
        while(mNextEvent < mEvents.size() && wxAtof(mEvents[mNextEvent]->GetNode()->GetAttribute(L"time")) <= elapsed)
        {
            // Process this event
            auto event = mEvents[mNextEvent];

            for(auto component : mComponents)
            {
                if(component->GetName() == event->GetNode()->GetAttribute(L"target"))
                {
                    component->XmlLoad(event->GetNode());
                }
            }

            mNextEvent++;
        }

        for (auto component : mComponents)
        {
            component->SetTime(elapsed);

        }
    } else
    {
        for (auto component : mComponents)
        {
            component->Reset(0);

            mNextEvent = 0;
        }
    }
}

/**
 * Adds a component to the lab
 * @param component Component being added
 */
void ActualLaboratory::AddComponent(std::shared_ptr<Component> component)
{
    mComponents.push_back(component);
    component->SetLaboratory(this);
}
