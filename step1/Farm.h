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
#include "Cow.h"

class Farm {
private:
    /// A list with the inventory of all animals on the farm
    std::vector<Cow *> mInventory;

public:
    void AddAnimal(Cow *cow);
    void DisplayInventory();
    ~Farm();

};

#endif //STEP1_FARM_H
