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

/** Class that describes a chicken.
*/
class Chicken
{
private:
    /// The chicken's ID
    std::string mId;

public:

    void ObtainChickenInformation();
    void DisplayAnimal();

};


#endif //STEP1_CHICKEN_H