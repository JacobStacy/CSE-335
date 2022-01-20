/**
 * @file Animal.h
 * @author Jacob R. Stacy
 *
 *
 */

#ifndef STEP1_ANIMAL_H
#define STEP1_ANIMAL_H


class Animal {
public:
    virtual ~Animal();
    /** Display an animal. */
    virtual void DisplayAnimal() {}
    virtual bool IsDefender() {return false;}

};

#endif //STEP1_ANIMAL_H
