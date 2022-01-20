/**
 * @file Farm.h
 *
 * @author Jacob R. Stacy
 *
 *
 */

#ifndef STEP1_FARM_H
#define STEP1_FARM_H


#include <vector>
#include "Animal.h"

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
