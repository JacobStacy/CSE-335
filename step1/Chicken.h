/**
 * @file Chicken.h
 *
 * @author Jacob R. Stacy
 *
 * Declaration of the Chicken class.
 */

#ifndef STEP1_CHICKEN_H
#define STEP1_CHICKEN_H

#include <string>
#include "Animal.h"

/** Class that describes a chicken.
*/
class Chicken : public Animal
{
private:
    /// The chicken's ID
    std::string mId;

public:

    void ObtainChickenInformation();
    void DisplayAnimal();
    bool IsDefender();

};


#endif //STEP1_CHICKEN_H