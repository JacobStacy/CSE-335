/**
 * @file Farm.cpp
 *
 * @author Jacob R. Stacy
 *
 *
 *
 *
 */

#include <iostream>
#include "Farm.h"

/** Add an animal to the farm inventory.
 *
 * @param cow A cow to add to the inventory
 */
void Farm::AddAnimal(Animal *animal)
{
    mInventory.push_back(animal);
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
 * Output number of defenders.
 */
void Farm::DisplayDefenders()
{
    int count = 0;

    for (auto animal : mInventory)
    {
        if (animal->IsDefender()) {
            count++;
        }
    }

    std::cout << "There are " << count << " defenders" << std::endl;
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

