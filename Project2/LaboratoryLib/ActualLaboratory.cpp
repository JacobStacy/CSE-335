/**
 * @file ActualLaboratory.cpp
 * @author Jacob Stacy
 */

#include "pch.h"

#include <memory>

#include "ActualLaboratory.h"
#include "Component.h"

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
 * Handles changes in the lab over time
 * @param elapsed
 */
void ActualLaboratory::Update(double elapsed)
{

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
