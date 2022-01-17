/**
 * @file Cow.h
 * @author Jacob R. Stacy
 *
 *
 * Moo
 *
 */

#ifndef STEP1_COW_H
#define STEP1_COW_H

#include <string>
#include <vector>


class Cow {
private:
    /// A list with the inventory of all animals on the farm
    std::vector<Cow *> mInventory;

    /// The types of cow we can have on our farm
    enum class Type {Bull, BeefCow, MilkCow};

    /// The cow's name
    std::string mName;

    /// The type of cow: Bull, BeefCow, or MilkCow
    Type mType =Type::MilkCow;

    /// The milk production for a cow in gallons per day
    double mMilkProduction = 0;


public:

    void ObtainCowInformation();

    void DisplayAnimal();
};

#endif //STEP1_COW_H