/**
 * @file main.cpp
 *
 * @author Jacob R. Stacy
 *
 *
 *
 *
 */

#include "Farm.h"

/** Add an animal to the farm inventory.
 *
 * @param cow A cow to add to the inventory
 */
void Farm::AddAnimal(Cow *cow)
{
    mInventory.push_back(cow);
}

/**
 * Display the farm inventory.
 */
void Farm::DisplayInventory()
{
    for (auto animal : mInventory)
    {
        animal->DisplayAnimal();
    }
}

/**
 * Farm destructor
 */
Farm::~Farm()
{
    // Iterate over all of the animals, destroying
    // each one.
    for (auto animal : mInventory)
    {
        delete animal;
    }

    // And clear the list
    mInventory.clear();
}

