/**
 * @file Farm.h
 *
 * @author Jacob R. Stacy
 *
 * Declaration of the Farm class.
 *
 */

#ifndef STEP1_FARM_H
#define STEP1_FARM_H


#include <vector>
#include "Animal.h"

/** This class describes a farm
 */
class Farm {
private:
    /// A list with the inventory of all animals on the farm
    std::vector<Animal *> mInventory;

public:
    void AddAnimal(Animal *animal);
    void DisplayInventory();
    void DisplayDefenders();
    ~Farm();

};

#endif //STEP1_FARM_H
