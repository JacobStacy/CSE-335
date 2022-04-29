/**
 * @file ComponentTest.cpp
 * @author Jacob R. Stacy
 */

#include "pch.h"
#include "gtest/gtest.h"

#include <LaboratoryFactoryOne.h>
#include <ActualLaboratory.h>
#include <Component.h>

TEST(ComponentTest, Constructor)
{
    Component component(L"Name");
}

TEST(ComponentTest, Adding)
{
    auto actualLaboratory = std::make_shared<ActualLaboratory>();

    auto component = std::make_shared<Component>(L"Name");

    actualLaboratory->AddComponent(component);
}



