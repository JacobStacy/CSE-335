/**
 * @file Ant.h
 *
 * @author Jacob R. Stacy
 *
 * */

#ifndef STEP1_ANT_H
#define STEP1_ANT_H

#include <string>
#include "Animal.h"

class Ant : public Animal {
private:
    /// The types of ants we can have on the farm
    enum class Type {Worker, Soldier, Drone, Queen};

    /// The code for the ant on the farm
    std::string mCode;

    /// Type of ant: Worker,Soldier, Drown, or Queen
    Type mType =Type::Queen;

    /// Radiation level of this ant in millisieverts per hour
    double mRadiation = 0;

public:
    void ObtainAntInformation();

    void DisplayAnimal();

    bool IsDefender();

};

#endif //STEP1_ANT_H
