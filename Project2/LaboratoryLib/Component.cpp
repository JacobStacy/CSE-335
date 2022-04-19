/**
 * @file Component.cpp
 * @author Jacob Stacy
 */

#include "pch.h"

#include "Component.h"
#include "ActualLaboratory.h"


/**
 * Constructor
* @param name The component name */
Component::Component(const std::wstring &name) : mName(name)
{

}

/**
 * Set the parent laboratory
 * @param laboratory Parent laboratory
 */
void Component::SetLaboratory(ActualLaboratory *laboratory)
{
    mLaboratory = laboratory;
}
