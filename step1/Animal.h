/**
 * @file Animal.h
 *
 * @author Jacob R. Stacy
 *
 * Declaration of the Animal class.
 *
 */

#ifndef STEP1_ANIMAL_H
#define STEP1_ANIMAL_H

/** Objects of this class represents an animal.
 */
class Animal {
public:
    virtual ~Animal();
    /** Display an animal. */
    virtual void DisplayAnimal() {}
    /** Outputs if animal is a defender. */
    virtual bool IsDefender() {return false;}

};

#endif //STEP1_ANIMAL_H
